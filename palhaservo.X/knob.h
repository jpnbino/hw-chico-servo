/**
  Knob Module API Header File

  @Company
    Embedded Things

  @File Name
    knob.h

  @Summary
     This is the knob implementation source file.

  @Description
    This header file provides APIs for knob functionality.
	
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

#ifndef KNOB_H
#define KNOB_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include "knob_cfg.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types Definitions
*/


/**
 *  result of Knob Position Read
 */

typedef uint16_t knob_read_t;

/**
  Section: Knob Module APIs
*/

/**
  @Summary
    Initializes the Knob

  @Description
    This routine must be called before any other Knob routine is called.
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
    uint16_t knob_position;

    const VoltimeterConfig_t * voltimeter_cfg = Voltimeter_ConfigGet();
    Voltimeter_Init(voltimeter_cfg);
 
    knob_position = Knob_Position_Read();
    </code>
*/
void Knob_Init( const KnobConfig_t * const config);

/**
  @Summary
    Allows selection of a channel for conversion

  @Description
    This routine is used to select desired channel for conversion.
    available

  @Preconditions
    Knob_Init() function should have been called before calling this function.

  @Returns
    Returs the voltage value.

  @Param
    none

  @Example
    <code>
    uint16_t knob_position;

    Knob_Init();
    knob_position = Knob_Position_Read();
    </code>
*/
uint16_t Knob_Position_Read( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

