/**
  Application Header File

  @Company
    Embedded Things

  @File Name
    app_palhaservo.h

  @Summary
    This file is a application header file.

  @Description
    This header file provides APIs to perform proper application calling.
	
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

#ifndef APP_PALHASERVO_H
#define APP_PALHASERVO_H

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
 * Defines if the device will act as a master or a device
 */
typedef enum{
	MASTER,
	SLAVE,
	TEST,
    NOT_CONFIGURED,
    MAX_MODE,
}device_mode_t;


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
void    App_Palhaservo_Init ( void );
void    App_Palhaservo_Run  ( void );
void    Device_Set_Mode     (uint8_t mode);
uint8_t Device_Get_Mode     (void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//INIT_H
/**
 End of File
*/

