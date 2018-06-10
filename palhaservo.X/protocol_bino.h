/**
  Voltimeter Module API Header File

  @Company
    Embedded Things

  @File Name
    protocol_bino.h

  @Summary
     This is the reader file for the bino protocol.

  @Description
    This header file provides APIs and data shared for the use
	of bino protocol, a simple protocol to exchange data.
	
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

#ifndef PROTOCOL_BINO_H
#define PROTOCOL_BINO_H

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

/** Marks the beginnig of the Frame */
#define START_FLAG  0x7e
/** Marks the end of the Frame */
#define END_FLAG	0x7d

#define BINO_DATA_LEN 3
/**
  Section: Data Types Definitions
*/



/*
 * BINO Packet
 */ 
typedef struct 
{ 
    uint8_t start_flag;
	uint8_t cmd;
    uint8_t data[BINO_DATA_LEN];
	uint8_t end_flag;
} bino_pkt_t;



/**
  Section: Procotocol Module APIs
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
void Bino_Pkt_Snd(bino_pkt_t * pbino_pkt, uint16_t len);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

