#ifndef NRF24L01P_H
#define	NRF24L01P_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
    
//Register Map Address
#define NRF_CONFIG_ADDR  0x00
#define EN_AA_ADDR       0x01
#define EN_RXADDR_ADDR   0x02
#define SETUP_AW_ADDR    0x03
#define SETUP_RETR_ADDR  0x04
#define RF_CH_ADDR       0x05
#define RF_SETUP_ADDR    0x06
#define NRF_STATUS_ADDR  0x07
#define OBSERVE_TX_ADDR  0x08
#define CD_ADDR          0x09
#define RX_ADDR_P0_ADDR  0x0A
#define RX_ADDR_P1_ADDR  0x0B
#define RX_ADDR_P2_ADDR  0x0C
#define RX_ADDR_P3_ADDR  0x0D
#define RX_ADDR_P4_ADDR  0x0E
#define RX_ADDR_P5_ADDR  0x0F
#define TX_ADDR_ADDR     0x10
#define RX_PW_P0_ADDR    0x11
#define RX_PW_P1_ADDR    0x12
#define RX_PW_P2_ADDR    0x13
#define RX_PW_P3_ADDR    0x14
#define RX_PW_P4_ADDR    0x15
#define RX_PW_P5_ADDR    0x16
#define FIFO_STATUS_ADDR 0x17
#define DYNPD_ADDR       0x1C
#define FEATURE_ADDR     0x1D
    
//Instruction
#define R_REGISTER          0x00
#define W_REGISTER          0x20
#define REGISTER_MASK       0x1F
#define ACTIVATE            0x50
#define R_RX_PL_WID         0x60
#define R_RX_PAYLOAD        0x61
#define W_TX_PAYLOAD        0xA0
#define W_ACK_PAYLOAD       0xA8
#define W_TX_PAYLOAD_NO_ACK 0xB0
#define FLUSH_TX            0xE1
#define FLUSH_RX            0xE2
#define REUSE_TX_PL         0xE3
#define NRF_NOP             0xFF

//AW (Address Width) Values
#define AW_3bytes 0b01
#define AW_4bytes 0b10
#define AW_5bytes 0b11

//RF_PWR (Output Power) Values
#define RF_PWR_n18dbm   0b00
#define RF_PWR_n12dbm   0b01
#define RF_PWR_n6dbm    0b10
#define RF_PWR_0dbm     0b11
    
    
typedef union {
    struct {
        unsigned PRIM_RX:1;
        unsigned PWR_UP:1;
        unsigned CRCO:1;
        unsigned EN_CRC:1;
        unsigned MASK_MAX_RT:1;
        unsigned MASK_TX_DS:1;
        unsigned MASK_RX_DR:1;
        unsigned Reserved:1;
    };
    uint8_t byte;
}NRF_CONFIG_R;

typedef union {
    struct {
        unsigned ENAA_P0:1;
        unsigned ENAA_P1:1;
        unsigned ENAA_P2:1;
        unsigned ENAA_P3:1;
        unsigned ENAA_P4:1;
        unsigned ENAA_P5:1;
        unsigned reserved:2;
    };
    uint8_t byte;
}EN_AA_R;

typedef union {
    struct {
        unsigned ERX_P0:1;
        unsigned ERX_P1:1;
        unsigned ERX_P2:1;
        unsigned ERX_P3:1;
        unsigned ERX_P4:1;
        unsigned ERX_P5:1;
        unsigned Reserved:2;
    };
    uint8_t byte;
}EN_RXADDR_R;

typedef union {
    struct {
        unsigned AW:2;
        unsigned Reserved:6;
    };
    uint8_t byte;
}SETUP_AW_R;

typedef union {
    struct {
        unsigned ARC:4;
        unsigned ARD:4;
    };
    uint8_t byte;
}SETUP_RETR_R;

typedef union {
    struct {
        unsigned RF_CH:7;
        unsigned Reserved:1;
    };
    uint8_t byte;
}RF_CH_R;

typedef union {
    struct {
        unsigned Obsolete:1;
        unsigned RF_PWR:2;
        unsigned RF_DR_HIGH:1;
        unsigned PLL_LOCK:1;
        unsigned RF_DR_LOW:1;
        unsigned Reserved:1;
        unsigned CONT_WAVE:1;
    };
    uint8_t byte;
}RF_SETUP_R;


typedef union {
    struct {
        unsigned TX_FULL:1;
        unsigned RX_P_NO:3;
        unsigned MAX_RT:1;
        unsigned TX_DS:1;
        unsigned RX_DR:1;
        unsigned Reserved:1;
    };
    uint8_t byte;
}STATUS_R;

typedef union {
    struct {
        unsigned ARC_CNT:4;
        unsigned PLOS_CNT:4;
    };
    uint8_t byte;
}OBSERVE_TX_R;

typedef union {
    struct {
        unsigned RPD:1;
        unsigned Reserved:7;
    };
    uint8_t byte;
}RPD_R;

typedef union{
    uint8_t addresses[5];
    struct{
        uint8_t address_0;
        uint8_t address_1;
        uint8_t address_2;
        uint8_t address_3;
        uint8_t address_4;
    };
}RX_ADDR_P0_R;

typedef union{
    uint8_t addresses[5];
    struct{
        uint8_t address_0;
        uint8_t address_1;
        uint8_t address_2;
        uint8_t address_3;
        uint8_t address_4;
    };
}RX_ADDR_P1_R;

uint8_t RX_ADDR_P2_R;

uint8_t RX_ADDR_P3_R;

uint8_t RX_ADDR_P4_R;

uint8_t RX_ADDR_P5_R;

typedef union{
    uint8_t addresses[5];
    struct{
        uint8_t address_0;
        uint8_t address_1;
        uint8_t address_2;
        uint8_t address_3;
        uint8_t address_4;
    };
}TX_ADDR_R;

typedef union {
    struct {
        unsigned RX_PW_P0:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P0_R;    

typedef union {
    struct {
        unsigned RX_PW_P1:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P1_R;

typedef union {
    struct {
        unsigned RX_PW_P2:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P2_R;

typedef union {
    struct {
        unsigned RX_PW_P3:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P3_R;

typedef union {
    struct {
        unsigned RX_PW_P4:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P4_R;

typedef union {
    struct {
        unsigned RX_PW_P5:6;
        unsigned Reserved:2;
    };
    uint8_t byte;
}RX_PW_P5_R;

typedef union {
    struct {
        unsigned RX_EMPTY:1;
        unsigned RX_FULL:1;
        unsigned Reserved_0:2;
        unsigned TX_EMPTY:1;
        unsigned TX_FULL:1;
        unsigned TX_REUSE:1;
        unsigned Reserved_1:1;
    };
    uint8_t byte;
}FIFO_STATUS_R;

typedef union {
    struct {
        unsigned DPL_P0:1;
        unsigned DPL_P1:1;
        unsigned DPL_P2:1;
        unsigned DPL_P3:1;
        unsigned DPL_P4:1;
        unsigned DPL_P5:1;
        unsigned Reserved:2;
    };
    uint8_t byte;
}DYNPD_R;

typedef union {
    struct {
        unsigned EN_DYN_ACK:1;
        unsigned EN_ACK_PAY:1;
        unsigned EN_DPL:1;
        unsigned Reserved:5;
    };
    uint8_t byte;
}FEATURE_R;
    
typedef struct {
    uint8_t data[5]; //Length = 5 because the NRF24 registers with the highest data length are RX_ADDR_P0, RX_ADDR_P1 and TX_ADDR with 40 bits (5 bytes).
    uint8_t data_size;
}RegisterData_t;

typedef struct {
    uint8_t data[32]; //Length = 32 because it's the maximum payload length.
    uint8_t payload_size;
}Payload_t;


typedef enum {
    TX,RX
}RadioMode_t;

void R_Register(uint8_t register_address, RegisterData_t * data_bytes);
void W_Register(uint8_t register_address, RegisterData_t data_bytes);
void R_RX_Payload(Payload_t * payload_info);
void W_TX_Payload(Payload_t payload_info);
void Flush_TX(void);
void Flush_RX(void);
void Reuse_TX_PL(void);
uint8_t R_RX_PL_Wid(void);
void W_ACK_Payload(uint8_t pipe, Payload_t payload_info);
void W_TX_Payload_NO_ACK(Payload_t payload_info);
void nRF_NOP(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* NRF24L01P_H */

