/**
  Voltimeter Module API Header File

  @Company
    Embedded Things

  @File Name
    task_serial_rx.h

  @Summary
     This is the header file for the serial task receiver.

  @Description
    This header file provides APIs to run serial receive module.
    
 
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

#ifndef TASK_SERIAL_RX_H
#define TASK_SERIAL_RX_H

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
  Section: Serial Receiver Module APIs
*/

/**
  @Summary
    

  @Description
    

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
    Task_Serial_Rx();
    </code>
*/
void Task_Serial_Rx( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

