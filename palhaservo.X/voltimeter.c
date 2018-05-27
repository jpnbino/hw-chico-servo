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
	Voltage calculation from ADC is given:
	
	          Resistive 		ADC voltage step                 
			divider factor
			  
			    (r1)      (positive_vref - negative_vref)     
	Voltage = --------- X -------------------------------  X  adc_result
			  (r1 + r2)	         ADC_MAX_VALUE
	
     where,
        r1 - can be up to 500000 [Ohm].
        r2 - can be up to 500000 [Ohm].
        ADC_MAX_VALUE - can be up to (2^12)-1 or 4095. A 12-bit ADC.
        positive_vref - is the positive voltage reference for the ADC.
        negative_vref - is the negative voltage reference for the ADC.
        ADC_Result - is the result of the ADC conversion
 
        All equation between equals signal and adc_result is calculated as 
        convertion_factor.
        The result is given in millivolts.
  
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
static uint16_t positive_vref = 0;
static uint16_t negative_vref = 0;
static uint8_t adc_battery_channel = 0;
static float convertion_factor = 0;
static float adc_voltage_step = 0;
static float divider_factor = 0;


/**
  Section: Voltimeter Module APIs
*/

void Voltimeter_Init( const VoltimeterConfig_t * const config)
{
    //r1 and r2 are the resistors from a voltage divider
    uint32_t r1,r2;
    uint8_t circuit_topology = 0;
    
    adc_battery_channel = config->channel;
    
    
    circuit_topology = config->topology;
    if ( circuit_topology == VOLTIMETER_RESISTOR_DIVIDER)
    {
        r1 = config->resistance1;
        r2 = config->resistance2;
    }
    else if (circuit_topology == VOLTIMETER_DIRECT_INPUT)
    {
        /**These numbers are just representation of this topology so that r1/(r1+r2) equals 1
        */
        r1 = 1;
        r2 = 0;
    }
    
    positive_vref = config->positive_vref;
    negative_vref = config->negative_vref;
   
    /**
     * When performing division without floating-point proper care should be 
     * taken about rounding integers. In this a division 
     * 
     */
    
    divider_factor = (float)(r1+r2)/r1;
    adc_voltage_step = (float)(positive_vref - negative_vref)/(ADC_MAX_VALUE);
    convertion_factor = divider_factor * adc_voltage_step;
    
    //convertion_factor =(float)(((r1)/(r1+r2))*((positive_vref - negative_vref)/(ADC_MAX_VALUE)));
}

uint16_t Voltimeter_Read ( void )
{

    uint16_t adc_result = 0;
    uint16_t voltage = 0;
	
    adc_result = ADC_GetConversion(adc_battery_channel);
	
    voltage = (convertion_factor * adc_result);
    return voltage;
}


/**
 End of File
*/