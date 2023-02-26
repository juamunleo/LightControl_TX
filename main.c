#include "main.h"
#include "nrf24l01p_driver.h"
#include "mcc_generated_files/mcc.h"

bool interrupted = false;

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

    //TMR5_StopTimer();
    //TMR3_StopTimer();
    
    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    SPI_Open(SPI_DEFAULT);
    
    
    //App code:
    uint8_t nPulsations = 1; //Pulsation determines in the receiver if the message received is a new pulsation, so the output can be toggled.
    Payload_t payload = buildPayload(2, 0xAA, 0);
    
    RF24_t radio = radio_init();
    radio_setChannel(&radio, 5);
    radio_openWritingPipe(&radio, buildRegisterData(5, 0xEF, 0xAB, 0xC8, 0xF3, 0xD7));
    radio_openReadingPipe(&radio, 0, 2, buildRegisterData(5,0xEF, 0xAB, 0xC8, 0xF3, 0xD7));
    
    LED_SetHigh();
    __delay_ms(300);
    LED_SetLow();
    
    while(1){
        if(interrupted){
            radio_powerUp(&radio);
            payload.data[1] = nPulsations;
            nPulsations++;
            while(!BUTTON_GetValue()){
                LED_Toggle();
                sendBytes(&radio, payload);
                __delay_ms(50);
            }
            interrupted = false;
            LED_SetLow();
            __delay_ms(500);
        }else{
            radio_powerOff(&radio);
            SLEEP();
        }
    }
}

/**
 End of File
*/
