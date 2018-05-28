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

#ifndef SERVOMOTOR_CFG_H
#define SERVOMOTOR_CFG_H

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
        

/** HARDWARE dependent definition
 * This values were found based on
 * practical test using a 9g micro
 * servomotor.
 * with a period of 19.968ms.
 * the minor servo angle was at
 * 770us pulse and the longest
 * at 2.013ms pulse.
 */
/** CCPR Register values - 770us pulse*/
#define SERVO_DUTY_MIN 24U
/** CCPR Register values - 770us pulse*/
#define SERVO_DUTY_MAX 63U      
        
/**
  Section: Data Types Definitions
*/


typedef struct
{
	uint8_t channel; 		 /** ADC channel*/
}ServoConfig_t;

/**
  Section: Servomotor Channel
*/
typedef enum 
{
	SERVO1,			/** Voltage read directly in the analog pin*/
	SERVO_MAX_NUMBER,	/** MAX number of servomotors */
}ServoChannel_t;

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
const ServoConfig_t * const Servo_ConfigGet( void );



#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//SERVOMOTOR_CFG_H
/**
 End of File
*/

