/**
  Voltimeter Module API Header File

  @Company
    Embedded Things

  @File Name
    voltimeter_cfg.h

  @Summary
     This is the voltimeter implementation source file.

  @Description
    This header file provides APIs for voltimeter functionality.
    Generation Information :
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

#ifndef KNOB_CFG_H
#define KNOB_CFG_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
/**
  Section: Macro Declarations
*/
        
/** When using voltage division in the analog input pin:
R1 - Defines the value of the resistor connected between the 
Voltage to be read and the ADC input pin its value is in OHM
unit. 
R2 - defines the resistor value connected between ADC input
and ground

Resistance is given in OHM unit
*/
#define RESISTANCE_R1 10000
#define RESISTANCE_R2 10000


/** Voltage is represented in millivolts*/
/** Defines positive voltage reference */
#define POSITIVE_VREF 3230U
/** Defines negative voltage reference */
#define NEGATIVE_VREF 0U      
/** The max converted value in the adc */
#define ADC_MAX_VALUE 1023U
        
        
        
/**
  Section: Data Types Definitions
*/
typedef struct
{
	uint8_t channel; 		 /** ADC channel*/
}KnobConfig_t;

/**
  Section: Data Types Definitions
*/



/**
  Section: Voltimeter Module APIs
*/

/**
  @Description
    This function returns the configuration table to initialize voltimeter
	module.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    Check configuration table VoltimeterConfig[] 

  @Example
    <code>
    const KnobConfig_t * KnobConfig = Knob_ConfigGet();

    Voltimeter_Init(VoltimeterConfig);   
    </code>
	@see Knob_Init
*/
const KnobConfig_t * const Knob_ConfigGet( void );



#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

