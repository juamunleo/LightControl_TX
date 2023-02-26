#include <stdarg.h>
#include "nrf24l01p_driver.h"

RF24_t radio_init(void){
    RF24_t radio;
    
    //CONFIG
    radio.NRF_CONFIG.MASK_RX_DR = 1;
    radio.NRF_CONFIG.MASK_MAX_RT = 1;
    radio.NRF_CONFIG.MASK_TX_DS = 1;
    radio.NRF_CONFIG.EN_CRC = 1;
    radio.NRF_CONFIG.CRCO = 1;
    
    //EN_AA
    radio.EN_AA.ENAA_P0 = 1;
    radio.EN_AA.ENAA_P1 = 1;
    radio.EN_AA.ENAA_P2 = 1;
    radio.EN_AA.ENAA_P3 = 1;
    radio.EN_AA.ENAA_P4 = 1;
    radio.EN_AA.ENAA_P5 = 1;
    
    //EN_RXADDR
    radio.EN_RXADDR.ERX_P0 = 1;
    radio.EN_RXADDR.ERX_P1 = 1;
    
    //SETUP_AW
    radio.SETUP_AW.AW = AW_5bytes;
    
    //SETUP_RETR
    radio.SETUP_RETR.ARC = 0xF;
    radio.SETUP_RETR.ARD = 0x5;
    
    //RF_SETUP
    radio.RF_SETUP.RF_DR_HIGH = 1;
    radio.RF_SETUP.RF_PWR = RF_PWR_0dbm;
    
    //config register    
    W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio.NRF_CONFIG.byte));
    
    //RETR    
    W_Register(SETUP_RETR_ADDR, buildRegisterData(1, radio.SETUP_RETR.byte));
    
    radio_setChannel(&radio, 2);
    
    radio_clearInterrupts();
    
    Flush_RX();
    
    Flush_TX();
    
    return radio;
}

void radio_openWritingPipe(RF24_t * radio, RegisterData_t address){
    if(address.data_size > 0){
        radio->TX_ADDR.address_0 = address.data[0];
        radio->TX_ADDR.address_1 = address.data[1];
        radio->TX_ADDR.address_2 = address.data[2];
        radio->TX_ADDR.address_3 = address.data[3];
        radio->TX_ADDR.address_4 = address.data[4];
        W_Register(TX_ADDR_ADDR, address);
    }
}

void radio_openReadingPipe(RF24_t * radio, uint8_t pipe, uint8_t bytesToReceive, RegisterData_t address){
    if(address.data_size > 0 && pipe < 6 && bytesToReceive < 33){
        switch(pipe){
            case 0:
                radio->RX_ADDR_P0.address_0 = address.data[0];
                radio->RX_ADDR_P0.address_1 = address.data[1];
                radio->RX_ADDR_P0.address_2 = address.data[2];
                radio->RX_ADDR_P0.address_3 = address.data[3];
                radio->RX_ADDR_P0.address_4 = address.data[4];
                radio->RX_PW_P0.RX_PW_P0 = bytesToReceive;
                break;
                
            case 1:
                radio->RX_ADDR_P1.address_0 = address.data[0];
                radio->RX_ADDR_P1.address_1 = address.data[1];
                radio->RX_ADDR_P1.address_2 = address.data[2];
                radio->RX_ADDR_P1.address_3 = address.data[3];
                radio->RX_ADDR_P1.address_4 = address.data[4];
                radio->RX_PW_P1.RX_PW_P1 = bytesToReceive;
                break;
                
            case 2:
                radio->RX_ADDR_P2 = address.data[0];
                radio->RX_PW_P2.RX_PW_P2 = bytesToReceive;
                break;
                
            case 3:
                radio->RX_ADDR_P3 = address.data[0];
                radio->RX_PW_P3.RX_PW_P3 = bytesToReceive;
                break;
            
            case 4: 
                radio->RX_ADDR_P4 = address.data[0];
                radio->RX_PW_P4.RX_PW_P4 = bytesToReceive;
                break;
            
            case 5:
                radio->RX_ADDR_P5 = address.data[0];
                radio->RX_PW_P5.RX_PW_P5 = bytesToReceive;
                break;
                
            default:
                break;
        }
        W_Register(RX_ADDR_P0_ADDR + pipe, address);
        W_Register(RX_PW_P0_ADDR + pipe, buildRegisterData(1,bytesToReceive));
    }
}

void radio_setChannel(RF24_t * radio, uint8_t channel){
    if(channel < 128){
        radio->RF_CH.RF_CH = channel;
        W_Register(RF_CH_ADDR, buildRegisterData(1, channel));
    }
}

void radio_startRx(RF24_t * radio){
    if(radio->NRF_CONFIG.PRIM_RX != RX){
        radio->NRF_CONFIG.PRIM_RX = RX;
        W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio->NRF_CONFIG.byte));
    }
    CE_HIGH();
}

static void radio_startTx(RF24_t * radio){
    if(radio->NRF_CONFIG.PRIM_RX != TX){
        radio->NRF_CONFIG.PRIM_RX = TX;
        W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio->NRF_CONFIG.byte));
    }
    CE_HIGH();
}

void radio_powerUp(RF24_t * radio){
    radio->NRF_CONFIG.PWR_UP = 1;
    
    W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio->NRF_CONFIG.byte));
}

void radio_powerOff(RF24_t * radio){    
    radio->NRF_CONFIG.PWR_UP = 0;
    
    W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio->NRF_CONFIG.byte));
}


void sendBytes(RF24_t * radio, Payload_t payloadInfo){
    RegisterData_t status = buildRegisterData(1, 0);
    uint8_t timeout = 0;
    
    //Send Data
    W_TX_Payload(payloadInfo);
    radio_startTx(radio);
    if(!radio->NRF_CONFIG.MASK_TX_DS){
        while(IRQ_GetValue() && timeout<255){
            timeout++;
        }
    }else{
        while((status.data[0]&0x20) != 0x20 && timeout<255){
            R_Register(NRF_STATUS_ADDR, &status);
            timeout++;
        }
    }
    CE_LOW();
    
    radio_clearInterrupts();
    
    Flush_TX();
}

Payload_t receiveBytes(uint8_t size){
    Payload_t payloadInfo = buildPayload(0);
    
    if(size > 0){
        payloadInfo.payload_size = size;
        R_RX_Payload(&payloadInfo);
    }
    
    Flush_RX();
    return payloadInfo;
}

bool checkFIFO(RF24_t * radio){
    bool data_exists = false;
    RegisterData_t data_bytes = buildRegisterData(0);
    
    data_bytes.data_size = 1;
    
    R_Register(FIFO_STATUS_ADDR, &data_bytes);
    
    radio->FIFO_STATUS.byte = data_bytes.data[0];
    if(!radio->FIFO_STATUS.RX_EMPTY){
        data_exists = true;
    }
    
    return data_exists;
}

Payload_t buildPayload(uint8_t size, ...){
    Payload_t payload = {{0x00}, 0x00};
    payload.payload_size = size < 33?size:32;
    
    if(size > 0){
        va_list arguments;
        va_start(arguments, size);
        for(uint8_t i = 0;i<payload.payload_size;i++){
            payload.data[i] = va_arg(arguments, uint8_t);
        }
        va_end(arguments);
    }
    return payload;
}

RegisterData_t buildRegisterData(uint8_t size, ...){
    RegisterData_t dataBytes = {{0x00}, 0x00};
    dataBytes.data_size = size < 6?size:5;
    
    if(size > 0){
        va_list arguments;
        va_start(arguments, size);
        for(uint8_t i = 0;i<dataBytes.data_size;i++){
            dataBytes.data[i] = va_arg(arguments, uint8_t);
        }
        va_end(arguments);
    }
    return dataBytes;
}

void radio_clearInterrupts(void){
    RegisterData_t clearInterrupts = buildRegisterData(1, 0x70);
    
    //Clear interrupts
    W_Register(NRF_STATUS_ADDR, clearInterrupts);
}

void radio_enableTX_DS(RF24_t * radio){
    radio->NRF_CONFIG.MASK_TX_DS = 0;
    W_Register(NRF_CONFIG_ADDR, buildRegisterData(1, radio->NRF_CONFIG.byte));
}