/**
  App Module Source File

  @Company
    Embedded Things

  @File Name
    app_palhaservo.c

  @Summary
    Runs application.

  @Description
    This module calls every necessary modules to run the palhaservo application.
  
    Development Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF1824
        Driver Version    :  1.00
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
  Section: Abbreviation

*/
enum{
    NOT_CONNECTED = 0,
    CONNECTED = 1,
};


/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"

#include "app_palhaservo.h"

#include "task_battery_manager.h"
#include "task_knob_manager.h"
#include "task_servo_manager.h"
#include "task_serial_rx.h"

/**
  Section: Global variables
*/
static uint8_t device_mode = NOT_CONFIGURED;

/**
  Section: Init Module APIs
*/

void App_Palhaservo_Init ( void )
{
    volatile uint8_t aux_device_role;
    
    aux_device_role = IO_RC1_GetValue();
	
    Device_Set_Mode( aux_device_role );
    
    /**
     * Inicia o módulo bluetooth
     */
    if ( Device_Get_Mode() == MASTER)
    {   
        volatile uint8_t aux_device_connected = 0;
        
        while ( aux_device_connected == NOT_CONNECTED )
        {
            __delay_ms(1000);
            printf("AT+DEFAULT\r\n");

            __delay_ms(1000);
            printf("AT+POWE3\r\n");
            
            __delay_ms(1000);
            printf("AT+ROLE1\r\n");

            __delay_ms(1000);
            printf("AT+INQ\r\n");

            __delay_ms(5000);
            printf("AT+CONN1\r\n");
            __delay_ms(500);
            aux_device_connected = IO_RC3_GetValue();
        }
    }
    else if( Device_Get_Mode() == SLAVE )
    {
        __delay_ms(1000);
        printf("AT+DEFAULT\r\n");
        
        __delay_ms(1000);
        printf("AT+POWE3\r\n");

        __delay_ms(1000);
        printf("AT+ROLE0\r\n"); 
    }
}

void App_Palhaservo_Run( void )
{
    if ( Device_Get_Mode() == MASTER )
    {
        uint8_t i;
        if(i >= 16)
        {
            Task_Knob_Manager();
            i = 0;
        }
        else
        {
            ++i;
        }
    }
    else if ( Device_Get_Mode() == SLAVE )
    {
        Task_Servo_Manager();
    }
    Task_Serial_Rx();
    Task_Battery_Manager();       
}

void Device_Set_Mode (uint8_t mode)
{
    if ( mode < MAX_MODE)
    {
        device_mode = mode;
    }
}

uint8_t Device_Get_Mode ( void )
{
    return device_mode;
}
/**
 End of File
*/