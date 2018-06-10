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

#ifndef TASK_SERIAL_H
#define TASK_SERIAL_H

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
#define LOW_BATTERY_VOLTAGE 3800U

/**
  Section: Voltimeter Module APIs
*/

/**
  @Summary
    Runs servomotor manager.

  @Description
    This routine reads a rotary potenciometer
	position and then converts its position into
	sermotor position and post a command for the servomotor
	via serial.

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
    Task_Servo_Manager();
    </code>
*/
void Task_Serial( void );


void Receive_Pkt ( char rx_data_byte );
void Process_Pkt ( void );

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

