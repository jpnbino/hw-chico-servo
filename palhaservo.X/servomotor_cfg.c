/**
  Voltimeter Module Source File

  @Company
    Embedded Things

  @File Name
    knob_cfg.c

  @Summary
    This is the knob configuration implementation source file.

  @Description
    This source file provides implementations to read voltage on a selected analog channel.
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
  Section: Included Files
*/

#include <xc.h>
#include "servomotor_cfg.h"
#include "mcc_generated_files/epwm1.h"

/**
 *  Configuration table
 */

const ServoConfig_t ServomotorConfig[] =
 {
//		PWM			
//		Channel		
	{SERVO1		}
 };

/**
  Section: Voltimeter Module APIs
*/
const ServoConfig_t * const Servo_ConfigGet( void )
{
	/*
	The cast states that the returned pointer is of type const
	so it can NOT be changed, read-only.
	*/
    return &ServomotorConfig[0];
}


/**
 End of File
*/