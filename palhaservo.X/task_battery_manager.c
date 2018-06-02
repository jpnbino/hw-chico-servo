/**
  Battery manger module Source File

  @Company
    Embedded Things

  @File Name
    task_battery_manager.c

  @Summary
    This is the battery manager implementation source file.

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
#include "task_battery_manager.h"
#include "voltimeter.h"
#include "mcc_generated_files/mcc.h"
/**
  Section: Macro Declarations
*/



/**
  Section: Global Variables
*/



/**
  Section: Battery manager Module APIs
*/

void Task_Battery_Manager( void )
{
	voltage_read_t voltage_value;
	
	voltage_value = Voltimeter_Read();
	
	if (voltage_value > LOW_BATTERY_VOLTAGE)
	{
		IO_RA5_SetLow();
	}
	else
	{
		IO_RA5_SetHigh();   
	}
}


/**
 End of File
*/