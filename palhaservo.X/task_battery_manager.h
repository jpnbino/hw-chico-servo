/**
  Voltimeter Module API Header File

  @Company
    Embedded Things

  @File Name
    task_battery_manager.h

  @Summary
     This is the reader file for the battery manager task.

  @Description
    This header file provides APIs for the battery manager task.
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

#ifndef TASK_BATTERY_MANAGER_H
#define TASK_BATTERY_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

/** Reference battery voltage. Below this voltage
the battery manager will throw a low battery alert.
The value is in milivolts unit.
*/
#define LOW_BATTERY_VOLTAGE 3500U

/**
  Section: Voltimeter Module APIs
*/

/**
  @Summary
    Runs battery manager.

  @Description
    This routine reads the voltage in a pin defined
	as voltimeter. If the voltage read indicate a 
	value minor than LOW_BATTERY_VOLTAGE, a led alert
	turns on.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    None

  @Example
    <code>
    Task_Battery_Manager();
    </code>
*/
void Task_Battery_Manager( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

