/**
  Servomotor manager module Source File

  @Company
    Embedded Things

  @File Name
    task_knob_manager.c

  @Summary
    This is the servomotor manager implementation source file.

  @Description
	
  
    Development Information :
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
/**
  Section: Abbreviation
    vref stands for Voltage reference
*/
/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#include "task_servo_manager.h"
#include "knob_cfg.h"
#include "knob.h"
#include "servomotor.h"
#include "utils.h"
#include "protocol_bino.h"
/**
  Section: Macro Declarations
*/



/**
  Section: Global Variables
*/



/**
  Section: Battery manager Module APIs
*/

void Task_Knob_Manager( void )
{
    uint16_t convertedValue;
    bino_pkt_t knob_pkt;
    
    convertedValue = Knob_Position_Read();
    convertedValue = Rescale_Value(convertedValue,200,800, SERVO_DUTY_MIN, SERVO_DUTY_MAX);
    
    knob_pkt.cmd = 'S';
    knob_pkt.data[0] = convertedValue & 0xff;
    knob_pkt.data[1] = (convertedValue >> 8) & 0xff;
            
    Bino_Pkt_Snd(&knob_pkt,2);
    //Servomotor_Set_Position(SERVO1,convertedValue);
}


/**
 End of File
*/