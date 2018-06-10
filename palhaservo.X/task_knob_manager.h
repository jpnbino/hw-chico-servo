/**
  Task Knob Module API Header File

  @Company
    Embedded Things

  @File Name
    task_knob_manager.h

  @Summary
     This is the reader file for the knob task.

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

#ifndef TASK_KNOB_MANAGER_H
#define TASK_KNOB_MANAGER_H

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



/**
  Section: Task Knob Module APIs
*/

/**
  @Summary
    Runs knob manager.

  @Description
    This routine reads a rotary potenciometer
	position and then converts its position into
	sermotor position and then sends the data
	via BINO protocol.

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
    Task_knob_Manager();
    </code>
*/
void Task_Knob_Manager( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

