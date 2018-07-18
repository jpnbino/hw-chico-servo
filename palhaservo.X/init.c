/**
  Init Module Source File

  @Company
    Embedded Things

  @File Name
    init.c

  @Summary
    Initializes application.

  @Description
    This module contains all the necessary initialization sequence for the
	applacation ( components, modules, system ).
  
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
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#include "init.h"

#include "voltimeter_cfg.h"
#include "voltimeter.h"

#include "knob_cfg.h"
#include "knob.h"
/**
  Section: Macro Declarations
*/


/**
  Section: Init Module APIs
*/

void Init ( void )
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    printf("\n\r START \n\r ");
    
    const VoltimeterConfig_t * voltimeter_cfg = Voltimeter_ConfigGet();
    Voltimeter_Init(voltimeter_cfg);
    
    const KnobConfig_t * knob_cfg = Knob_ConfigGet();
    Knob_Init(knob_cfg);
    
    volatile static uint8_t device_role;
    
    device_role = IO_RC1_GetValue();
    if ( device_role == MASTER)
    {
        IO_RA5_SetLow();
        __delay_ms(100);
        IO_RA5_SetHigh();
        __delay_ms(100);
        IO_RA5_SetLow();
        __delay_ms(100);
        IO_RA5_SetHigh();
        __delay_ms(100);
    }
    else if ( device_role == SLAVE )
    {
        IO_RA5_SetLow();
        __delay_ms(50);
        IO_RA5_SetHigh();
        __delay_ms(50);
        IO_RA5_SetLow();
        __delay_ms(50);
        IO_RA5_SetHigh();
        __delay_ms(50);
    }
    
    /**
     * Inicia o módulo bluetooth
     */
    if ( device_role == MASTER)
    {
        __delay_ms(1000);
        printf("AT+INQ\r\n");

        __delay_ms(1000);
        printf("AT+CONN1\r\n");
    }


}



/**
 End of File
*/