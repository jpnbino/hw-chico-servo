/**
  Servomotor manager module Source File

  @Company
    Embedded Things

  @File Name
    protocol_bino.c

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
    vref stands for Voltage reference
*/
/**
  Section: Included Files
*/
#include "protocol_bino.h"
#include "mcc_generated_files/mcc.h"
/**
  Section: Macro Declarations
*/



/**
  Section: Global Variables
*/



/**
  Section: Battery manager Module APIs
*/

void Bino_Pkt_Snd(bino_pkt_t * pbino_pkt, uint16_t len)
{
	    pbino_pkt->start_flag = START_FLAG;
        pbino_pkt->end_flag = END_FLAG;
        
#if 1		
		putch(pbino_pkt->start_flag);
        
		putch(pbino_pkt->cmd);
              
		putch(pbino_pkt->data[0]);
		putch(pbino_pkt->data[1]);
        
        putch(pbino_pkt->end_flag);
#endif   
    
}


/**
 End of File
*/