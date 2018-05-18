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

#ifndef VOLTIMETER_CFG_H
#define VOLTIMETER_CFG_H

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
  Section: Data Types Definitions
*/
typedef struct
{
	uint8_t channel; 		 /** ADC channel*/
	uint8_t negative_vref;  /** Positive voltage reference*/
	uint8_t positive_vref;  /** Positive voltage reference*/
	uint8_t topology;       /** Circuit topology*/ 
    uint16_t resistance1;    /** Resistor division factor*/ 
    uint16_t resistance2;    /** Resistor division factor*/ 
	
}VoltimeterConfig_t;

/**
  Section: Data Types Definitions
*/
typedef enum 
{
	VOLTIMETER_DIRECT_INPUT,			/** Voltage read directly in the analog pin*/
	VOLTIMETER_RESISTOR_DIVIDER,		/** Voltage read thru resistor division*/
	VOLTIMETER_MAX_TOPOLOGY, 			/** MAX topologies types */
}InputTopology_t;


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
    

  @Example
    <code>
    const VoltimeterConfig_t *VoltimeterConfig = Voltimeter_ConfigGet();

    Voltimeter_Init(VoltimeterConfig);   
    </code>
	@see Voltimeter_Init
*/
const VoltimeterConfig_t * const Voltimeter_ConfigGet( void );



#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

