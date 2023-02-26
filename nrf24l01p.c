#include "nrf24l01p.h"
#include "nrf24l01p_driver_definitions.h"

void R_Register(uint8_t register_address, RegisterData_t * data_bytes){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(R_REGISTER | register_address);
    for(i = 0;i < data_bytes->data_size;i++){
        data_bytes->data[i] = SPI_EXCHANGE_BYTE(0xFF);
    }
    SPI_OFF();
}

void W_Register(uint8_t register_address, RegisterData_t data_bytes){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(W_REGISTER | register_address);
    for(i=0;i<data_bytes.data_size;i++){
         SPI_EXCHANGE_BYTE(data_bytes.data[i]);
    }
    SPI_OFF();
}

void R_RX_Payload(Payload_t * payload_info){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(R_RX_PAYLOAD);
    for(i=0;i<payload_info->payload_size;i++){
         payload_info->data[i] = SPI_EXCHANGE_BYTE(0xFF);
    }
    SPI_OFF();
}

void W_TX_Payload(Payload_t payload_info){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(W_TX_PAYLOAD);
    for(i=0;i<payload_info.payload_size;i++){
         SPI_EXCHANGE_BYTE(payload_info.data[i]);
    }
    SPI_OFF();
}

void Flush_TX(void){
    SPI_ON();
    SPI_EXCHANGE_BYTE(FLUSH_TX);
    SPI_OFF();
}

void Flush_RX(void){
    SPI_ON();
    SPI_EXCHANGE_BYTE(FLUSH_RX);
    SPI_OFF();
}

void Reuse_TX_PL(void){
    SPI_ON();
    SPI_EXCHANGE_BYTE(REUSE_TX_PL);
    SPI_OFF();
}

uint8_t R_RX_PL_Wid(void){
    uint8_t width = 0;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(R_RX_PL_WID);
    width = SPI_EXCHANGE_BYTE(0xFF);
    SPI_OFF();
    
    return width;
}

void W_ACK_Payload(uint8_t pipe, Payload_t payload_info){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(W_ACK_PAYLOAD | pipe);
    for(i=0;i<payload_info.payload_size;i++){
         SPI_EXCHANGE_BYTE(payload_info.data[i]);
    }
    SPI_OFF();
}

void W_TX_Payload_NO_ACK(Payload_t payload_info){
    uint8_t i;
    
    SPI_ON();
    SPI_EXCHANGE_BYTE(W_TX_PAYLOAD_NO_ACK);
    for(i=0;i<payload_info.payload_size;i++){
         SPI_EXCHANGE_BYTE(payload_info.data[i]);
    }
    SPI_OFF();
}

void nRF_NOP(void){
    SPI_ON();
    SPI_EXCHANGE_BYTE(0xFF);
    SPI_OFF();
}