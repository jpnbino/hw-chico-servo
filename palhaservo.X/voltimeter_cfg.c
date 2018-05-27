/**
  Voltimeter Module Source File

  @Company
    Embedded Things

  @File Name
    voltimeter_cfg.c

  @Summary
    This is the voltimeter configuration implementation source file.

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
#include "voltimeter_cfg.h"
#include "mcc_generated_files/adc.h"

/**
 *  Configuration table
 */

const VoltimeterConfig_t VoltimeterConfig[] =
 {
//		ADC			Negative 			Positive 			Topology				RESISTOR		RESISTOR
//		Channel		Voltage Ref 		Voltage Ref										R1				R2
	{channel_AN3, 	NEGATIVE_VREF,	POSITIVE_VREF, VOLTIMETER_RESISTOR_DIVIDER, RESISTANCE_R1, RESISTANCE_R2}
 };

/**
  Section: Voltimeter Module APIs
*/

const VoltimeterConfig_t * const Voltimeter_ConfigGet( void )
{
	/*
	The cast states that the returned pointer is of type const
	so it can NOT be changed, read-only.
	*/
    return &VoltimeterConfig[0];
}


/**
 End of File
*/