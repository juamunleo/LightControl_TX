#ifndef DRIVER_DEFINITIONS_H
#define	DRIVER_DEFINITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/spi.h"
#include "mcc_generated_files/pin_manager.h"
    
#define SPI_ON CSN_SetLow
#define SPI_OFF CSN_SetHigh
#define CE_HIGH CE_SetHigh
#define CE_LOW CE_SetLow
#define SPI_EXCHANGE_BYTE SPI_ExchangeByte
    
#ifdef	__cplusplus
}
#endif

#endif	/* DRIVER_DEFINITIONS_H */

