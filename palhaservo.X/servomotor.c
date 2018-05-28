/**
  Servomotor Module Source File

  @Company
    Embedded Things

  @File Name
    servomotor.c

  @Summary
	This is the servomotor implementation source file.

  @Description
    This source file provides implementations to control the position of servomotors
  
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
  Section: Included Files
*/
#include "mcc_generated_files/epwm1.h"
#include "servomotor.h"
/**
  Section: Macro Declarations
*/


/**
  Section: Global Variables
*/


/**
  Section: Servomotor Module APIs
*/

void Servomotor_Init( const ServoConfig_t * const config)
{

}

void Servomotor_Set_Position ( uint8_t servo_id, uint16_t pos )
{
    if ( pos < SERVO_DUTY_MIN )
    {
        return;
    }
    
    if (pos > SERVO_DUTY_MAX)
    {
        return;
    }
    
	switch ( servo_id )
	{
		case SERVO1:
			EPWM1_LoadDutyValue(pos);
		break;
		default:
		break;
	}
}

uint16_t Servomotor_Get_Position ( uint8_t servo_id )
{
    return 0;
}


/**
 End of File
*/