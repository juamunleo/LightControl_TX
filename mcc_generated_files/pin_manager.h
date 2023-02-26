/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16LF1764
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RELE aliases
#define RELE_TRIS                 TRISAbits.TRISA2
#define RELE_LAT                  LATAbits.LATA2
#define RELE_PORT                 PORTAbits.RA2
#define RELE_WPU                  WPUAbits.WPUA2
#define RELE_OD                   ODCONAbits.ODA2
#define RELE_ANS                  ANSELAbits.ANSA2
#define RELE_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RELE_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RELE_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RELE_GetValue()           PORTAbits.RA2
#define RELE_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RELE_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RELE_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define RELE_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define RELE_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define RELE_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define RELE_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define RELE_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA4
#define BUTTON_LAT                  LATAbits.LATA4
#define BUTTON_PORT                 PORTAbits.RA4
#define BUTTON_WPU                  WPUAbits.WPUA4
#define BUTTON_OD                   ODCONAbits.ODA4
#define BUTTON_ANS                  ANSELAbits.ANSA4
#define BUTTON_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA4
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA5
#define LED_LAT                  LATAbits.LATA5
#define LED_PORT                 PORTAbits.RA5
#define LED_WPU                  WPUAbits.WPUA5
#define LED_OD                   ODCONAbits.ODA5
#define LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_GetValue()           PORTAbits.RA5
#define LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set CSN aliases
#define CSN_TRIS                 TRISCbits.TRISC0
#define CSN_LAT                  LATCbits.LATC0
#define CSN_PORT                 PORTCbits.RC0
#define CSN_WPU                  WPUCbits.WPUC0
#define CSN_OD                   ODCONCbits.ODC0
#define CSN_ANS                  ANSELCbits.ANSC0
#define CSN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CSN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CSN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CSN_GetValue()           PORTCbits.RC0
#define CSN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CSN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CSN_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CSN_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CSN_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define CSN_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define CSN_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define CSN_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IRQ aliases
#define IRQ_TRIS                 TRISCbits.TRISC2
#define IRQ_LAT                  LATCbits.LATC2
#define IRQ_PORT                 PORTCbits.RC2
#define IRQ_WPU                  WPUCbits.WPUC2
#define IRQ_OD                   ODCONCbits.ODC2
#define IRQ_ANS                  ANSELCbits.ANSC2
#define IRQ_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IRQ_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IRQ_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IRQ_GetValue()           PORTCbits.RC2
#define IRQ_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IRQ_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IRQ_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IRQ_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IRQ_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define IRQ_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define IRQ_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IRQ_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)

// get/set CE aliases
#define CE_TRIS                 TRISCbits.TRISC5
#define CE_LAT                  LATCbits.LATC5
#define CE_PORT                 PORTCbits.RC5
#define CE_WPU                  WPUCbits.WPUC5
#define CE_OD                   ODCONCbits.ODC5
#define CE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define CE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define CE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define CE_GetValue()           PORTCbits.RC5
#define CE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define CE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define CE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define CE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define CE_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define CE_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/