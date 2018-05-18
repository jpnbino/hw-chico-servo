/**
  Voltimeter Module Source File

  @Company
    Embedded Things

  @File Name
    voltimeter.c

  @Summary
    This is the voltimeter implementation source file.

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
#include "mcc_generated_files/adc.h"
#include "voltimeter.h"
/**
  Section: Macro Declarations
*/

/*formula resistive voltage divider: Vin = R1/(R1+R2)  x Vadc
where, 	
	R2 is connected between Vadc and ground
	R1 is connected between Vin and Vadc
	
So, 
	R1/(R1+R2) is the RESISTOR_DIVIDER_FACTOR
*/


/**
  Section: Global Variables
*/
uint8_t voltage_positive_ref = 0;
uint8_t voltage_negative_ref = 0;
uint8_t adc_battery_channel = 0;
uint8_t divider_factor = 0;

/**
  Section: Voltimeter Module APIs
*/

void Voltimeter_Init( const VoltimeterConfig_t * const config)
{

}

uint8_t Voltimeter_Read ( void )
{
    uint16_t voltage = 0;
	voltage = ADC_GetConversion(adc_battery_channel);
	
    return voltage;
}


/**
 End of File
*/