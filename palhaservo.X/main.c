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
    Copyright
*/

#include "mcc_generated_files/mcc.h"

#include "init.h"
#include "app_palhaservo.h"

/**
  Section: Main application
 */
void main(void)
{
    Init();
    
    while (1)
    {
        App_Palhaservo_Run();
    }
}
/**
 End of File
*/