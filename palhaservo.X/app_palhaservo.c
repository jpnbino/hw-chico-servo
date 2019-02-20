/**
  App Module Source File

  @Company
    Embedded Things

  @File Name
    app_palhaservo.c

  @Summary
    Runs application.

  @Description
    This module calls every necessary modules to run the palhaservo application.
  
    Development Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF1824
        Driver Version    :  1.00
    The module is tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*/

/*
    Copyright
*/

/**
  Section: Abbreviation

*/

/**
  Section: Abbreviation

*/
enum{
    NOT_CONNECTED = 0,
    CONNECTED = 1,
};

//Finite State Machine
// ST stands for state
typedef enum{
    ST_INIT,
    ST_BATTERY_TASK,
    ST_DEAD_TIME,
    ST_KNOB_TASK,
    ST_SERVO_TASK,
    ST_SERIAL_TASK,
} state_t;

/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"

#include "app_palhaservo.h"

#include "task_battery_manager.h"
#include "task_knob_manager.h"
#include "task_servo_manager.h"
#include "task_serial_rx.h"

/**
  Section: Global variables
*/
static uint8_t device_mode = NOT_CONFIGURED;

/**
  Section: Init Module APIs
*/

void App_Palhaservo_Init ( void )
{
    volatile uint8_t aux_device_role;
    
    //a PULL-UP or PULL-DOWN resistor in Hardware
    aux_device_role = IO_RC1_GetValue();
	
    Device_Set_Mode( aux_device_role );
}

void App_Palhaservo_Run( void )
{  
    static uint8_t current_state = ST_INIT;
    static uint8_t dead_loop_counter = 0;
    
    switch (current_state)
    {
        case ST_INIT:
            
                App_Palhaservo_Init();
                current_state =  ST_BATTERY_TASK ;
                
            break;
                        
        case ST_BATTERY_TASK:

            Task_Battery_Manager(); 

            if ( Device_Get_Mode() == MASTER )
            {
                current_state = ST_DEAD_TIME;
            }
            else if ( Device_Get_Mode() == SLAVE )
            {
                current_state = ST_SERVO_TASK;  
            }
            
            if ( IO_RC3_GetValue() == NOT_CONNECTED )
            {
                current_state =  ST_BATTERY_TASK ;
            }

            break;

        case ST_DEAD_TIME:
            
            if(dead_loop_counter >= 16)
            {
                current_state = ST_KNOB_TASK;
                dead_loop_counter = 0;
            }
            else
            {
                ++dead_loop_counter;
            }
        break;
                
        case ST_KNOB_TASK:
            
            Task_Knob_Manager();            

            current_state = ST_SERIAL_TASK;

            break;

        case ST_SERVO_TASK:

            Task_Servo_Manager();
            current_state = ST_SERIAL_TASK;

            break;

        case ST_SERIAL_TASK:

            Task_Serial_Rx();
            current_state = ST_BATTERY_TASK;

            break;
        
        default:
            
        break;
    } 
}    


void Device_Set_Mode (uint8_t mode)
{
    if ( mode < MAX_MODE)
    {
        device_mode = mode;
    }
}

uint8_t Device_Get_Mode ( void )
{
    return device_mode;
}
/**
 End of File
*/