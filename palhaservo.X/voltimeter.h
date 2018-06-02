/**
  Voltimeter Module API Header File

  @Company
    Embedded Things

  @File Name
    voltimeter.h

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

#ifndef VOLTIMETER_H
#define VOLTIMETER_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include "voltimeter_cfg.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types Definitions
*/


/**
 *  result of Voltage Read
 */

typedef uint16_t voltage_read_t;

/**
  Section: Voltimeter Module APIs
*/

/**
  @Summary
    Initializes the Voltimeter

  @Description
    This routine must be called before any other Voltimeter routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    uint16_t voltage_value;

    const VoltimeterConfig_t * voltimeter_cfg = Voltimeter_ConfigGet();
    Voltimeter_Init(voltimeter_cfg);
 
    voltage_value = Voltimeter_Read();
    </code>
*/
void Voltimeter_Init( const VoltimeterConfig_t * const config);

/**
  @Summary
    Allows selection of a channel for conversion

  @Description
    This routine is used to select desired channel for conversion.
    available

  @Preconditions
    Voltimeter_Init() function should have been called before calling this function.

  @Returns
    Returs the voltage value.

  @Param
    none

  @Example
    <code>
    uint8_t voltage_value;

    Voltimeter_Initialize();
    voltage_value = Voltimeter_Read();
    </code>
*/
voltage_read_t Voltimeter_Read( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

