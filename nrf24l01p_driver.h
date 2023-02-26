#ifndef DRIVER_H
#define	DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "nrf24l01p.h"
#include "nrf24l01p_driver_definitions.h"


typedef struct {
    NRF_CONFIG_R NRF_CONFIG;

    EN_AA_R EN_AA;

    EN_RXADDR_R EN_RXADDR;

    SETUP_AW_R SETUP_AW;

    SETUP_RETR_R SETUP_RETR;

    RF_CH_R RF_CH;

    RF_SETUP_R RF_SETUP;

    STATUS_R NRF_STATUS;

    OBSERVE_TX_R OBSERVE_TX;

    RPD_R RPD;

    RX_ADDR_P0_R RX_ADDR_P0;

    RX_ADDR_P1_R RX_ADDR_P1;

    uint8_t RX_ADDR_P2;

    uint8_t RX_ADDR_P3;

    uint8_t RX_ADDR_P4;

    uint8_t RX_ADDR_P5;

    TX_ADDR_R TX_ADDR;

    RX_PW_P0_R RX_PW_P0;

    RX_PW_P1_R RX_PW_P1;

    RX_PW_P2_R RX_PW_P2;

    RX_PW_P3_R RX_PW_P3;

    RX_PW_P4_R RX_PW_P4;

    RX_PW_P5_R RX_PW_P5;

    FIFO_STATUS_R FIFO_STATUS;

    DYNPD_R DYNPD;

    FEATURE_R FEATURE;
}RF24_t;

void radio_powerUp(RF24_t * radio);
void radio_powerOff(RF24_t * radio);
RF24_t radio_init(void);
Payload_t buildPayload(uint8_t size, ...);
void sendBytes(RF24_t * radio, Payload_t payloadInfo);
Payload_t receiveBytes(uint8_t size);
RegisterData_t buildRegisterData(uint8_t size, ...);
bool checkFIFO(RF24_t * radio);
void radio_openWritingPipe(RF24_t * radio, RegisterData_t address);
void radio_openReadingPipe(RF24_t * radio, uint8_t pipe, uint8_t bytesToReceive, RegisterData_t address);
void radio_setChannel(RF24_t * radio, uint8_t channel);
void radio_startRx(RF24_t * radio);
void radio_enableTX_DS(RF24_t * radio);
void radio_clearInterrupts(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DRIVER_H */

