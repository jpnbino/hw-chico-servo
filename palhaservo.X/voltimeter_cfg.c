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
  Section: Macro Declarations
*/

/** When using voltage division in the analog input pin:
R1 - Defines the value of the resistor connected between the 
Voltage to be read and the ADC input pin its value is in OHM
unit. 
R2 - defines the resistor value connected between ADC input
and ground
*/
#define RESISTANCE_R1 10000
#define RESISTANCE_R2 10000

/** Defines positive voltage reference */
#define VOLTAGE_POS_REF 33
/** Defines negative voltage reference */
#define VOLTAGE_NEG_REF 0

/**
 *  Configuration table
 */

const VoltimeterConfig_t VoltimeterConfig[] =
 {
//		ADC			Negative 			Positive 			Topology				RESISTOR		RESISTOR
//		Channel		Voltage Ref 		Voltage Ref										R1				R2
	{channel_AN3, 	VOLTAGE_NEG_REF,	VOLTAGE_POS_REF, VOLTIMETER_RESISTOR_DIVIDER, RESISTANCE_R1, RESISTANCE_R2}
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
    return (const *)&VoltimeterConfig[0];
}


/**
 End of File
*/