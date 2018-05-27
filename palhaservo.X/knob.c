/**
  Knob Module Source File

  @Company
    Embedded Things

  @File Name
    knob.c

  @Summary
    This is the knob implementation source file.

  @Description
    This source file provides implementations to read the position of a rotary potetiometer 
	connected to an ADC mcu channel.
	
	This implementation takes into account that the potetiometer has the same voltage reference
	as the ADC.
  
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
#include "mcc_generated_files/adc.h"
#include "knob.h"
/**
  Section: Macro Declarations
*/


/**
  Section: Global Variables
*/
static uint8_t adc_knob_channel = 0;



/**
  Section: Knob Module APIs
*/

void Knob_Init( const KnobConfig_t * const config)
{
    adc_knob_channel = config->channel;

}

uint16_t Knob_Position_Read ( void )
{
    uint16_t knob_position = 0;
	
    knob_position = ADC_GetConversion(adc_knob_channel);

    return knob_position;
}


/**
 End of File
*/