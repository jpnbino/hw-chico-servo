/**
  Init Module API Header File

  @Company
    Embedded Things

  @File Name
    init.h

  @Summary
     This is the initialization header file.

  @Description
    This header file provides APIs to perform proper application initialization.
	
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

#ifndef INIT_H
#define INIT_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 * Defines if the device will act as a master or a device
 */
typedef enum{
    MASTER  = 0,
    SLAVE   = 1,
}device_role_t;


/**
  Section: Init Module APIs
*/

/**
  @Summary
    Initialize application

  @Description
    This routine initializes all the necessary components so that the application
	runs.

  @Preconditions
    none

  @Returns
    none

  @Param
    none

  @Example
    <code>
	// in main function
    Init();
	
    </code>
*/
void Init ( void );


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//INIT_H
/**
 End of File
*/

