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
#include "knob_cfg.h"
#include "mcc_generated_files/adc.h"

/**
 *  Configuration table
 */

const KnobConfig_t KnobConfig[] =
 {
//		ADC			
//		Channel		
	{channel_AN6}
 };

/**
  Section: Voltimeter Module APIs
*/

const KnobConfig_t * const Knob_ConfigGet( void )
{
	/*
	The cast states that the returned pointer is of type const
	so it can NOT be changed, read-only.
	*/
    return &KnobConfig[0];
}


/**
 End of File
*/