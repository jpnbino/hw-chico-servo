/**
  Servomotor manager module Source File

  @Company
    Embedded Things

  @File Name
    task_serial.c

  @Summary
    This is the servomotor manager implementation source file.

  @Description
	
  
    Development Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF1824
        Driver Version    :  2.01
    The module is tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*/

/*
    Copyright
*/
/**
  Section: Abbreviation

*/
/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#include "task_serial.h"
#include "protocol_bino.h"
#include "servomotor.h"

/**
  Section: Macro Declarations
*/
#define MAX_RX_STRING 10
#define	END_OF_STRING 1



enum{
	STATE_START = 0,
	STATE_CMD = 1,
	STATE_ITEM = 2,
	STATE_DATA_RECEIVE = 3,
	STATE_END = 4,
}SERIAL_RX_STATE;

enum{
    CMD_SERVO = 'S',
};


/**
  Section: Global Variables
*/
static bino_pkt_t rx_pkt;
static char rx_string[MAX_RX_STRING] = {0};
static uint8_t rx_index = 0;
volatile struct
{
	uint8_t inicio;
	uint8_t comando;
	uint8_t item;
	uint8_t dado;
	
	// implementar uso
	uint8_t dado2;
	uint8_t dado3;
	uint8_t dado4;
	uint8_t valido;
} sol;
/**
  Section: Battery manager Module APIs
*/

void Task_Serial( void )
{	
	/**
	Polls for received data
	Mount packet in Bino protocol format
	Verifies if there is packet available
	Process packet
	*/
	volatile uint8_t rx_data;
	// Logic to receive data
	while(EUSART_is_rx_ready())
	{
		rx_data = EUSART_Read();
		Receive_Pkt(rx_data);
	}
	
	Process_Pkt();
}
void Receive_Pkt ( char rx_data_byte )
{
	static int rxstate = 0;
    static int rx_data_size = 0;

	 /*switch( rxstate )
	Verifica os caracteres recebidos e se formam um pacote de comando
	válido do protocolo serial.
	
	Formato de pacote válido:
	Pacote = { INICIO, COMANDO, DADOS[63], FIM };
	*/
	if(rx_data_byte == END_FLAG)
	{
		rxstate = STATE_END;
	}

    switch( rxstate )
    {
		//Recebe inicio de pacote
        case STATE_START: 
            if(rx_data_byte == START_FLAG)
            {
				sol.inicio = rx_data_byte;
                rxstate = STATE_CMD;
				rx_string[0] = 0;
				rx_index = 0;
                rx_data_size = 0;
            }
            break;
			
		//Recebe comando   
        case STATE_CMD: 
            sol.comando = rx_data_byte;
            rxstate = STATE_ITEM;
            break;
			
        //Recebe item    
		case STATE_ITEM:
			sol.item = rx_data_byte;
			rxstate = STATE_DATA_RECEIVE;
			break;
			
		//Recebe os dados	
		case STATE_DATA_RECEIVE:
			
			rx_string[rx_index] = rx_data_byte;
			++rx_index;
			++rx_data_size;
          
            /*Se for maior, há um estouro no tamanho do array.*/
			if (rx_data_size > MAX_RX_STRING )
			{
				rxstate = STATE_START;
			}
			break;	
        
		//Aguardando fim de pacote
		case STATE_END: 
            if(rx_data_byte == END_FLAG)
            {
                sol.dado = rx_string[0];
                sol.dado2 = rx_string[1];
                sol.dado3 = rx_string[2];
                
                sol.valido = 1;
            }
        default:
            sol.inicio = 0;
            rxstate = STATE_START;
            break;			
    }
}
//mudar para processa pacote
void Process_Pkt ( void )
{
	/*If format pkt is not valid*/
    if(!sol.valido) 
    {
		return;
	}
	sol.valido = 0;
	
    //@teste
    uint16_t servo_pos = 0;
    
	switch ( sol.comando )
	{
		case CMD_SERVO:
                servo_pos = (rx_string[0]<<8)|(sol.item);
               
                /* useful debug information*/
                //printf("\n PWM POS %i ", servo_pos);
                
                Servomotor_Set_Position(SERVO1,servo_pos);
			break;

	}
	//Reset pkt
	sol.inicio = 0;
	sol.comando = 0;
	sol.item = 0;
	
}


/**
 End of File
*/