/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF1824
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#include "voltimeter_cfg.h"
#include "voltimeter.h"
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("\n\r here we go \n\r ");
    const VoltimeterConfig_t * voltimeter_cfg = Voltimeter_ConfigGet();
    Voltimeter_Init(voltimeter_cfg);
    
    while (1)
    {
        // Add your application code
        

        uint16_t convertedValue;

        convertedValue = Voltimeter_Read();
        printf("chan6 %i ", convertedValue);
        if (convertedValue > 1249)
        {
            IO_RA5_SetLow();
        }
        else
        {
            IO_RA5_SetHigh();   
        }
        
        convertedValue = ADC_GetConversion(channel_AN3);
        printf("chan3 %i ", convertedValue);
        EPWM1_LoadDutyValue((convertedValue)>>3);
#if 0 
        if (convertedValue > 250)
        {
            EPWM1_LoadDutyValue(30);
        }
        else
        {
            EPWM1_LoadDutyValue(40);   
        }     
#endif
#if 0 
        uint8_t i = 0 ;
        for (i=30;i<=61;i=i++)             // do a smooth rotation from right to left
        {
            EPWM1_LoadDutyValue(i);
            mydelay_ms(20);
        }
        for (i=61;i>=30;i=i--)             // do a smooth rotation from right to left
        {
            EPWM1_LoadDutyValue(i);
            mydelay_ms(20);
        }
#endif
    }
}
/**
 End of File
*/