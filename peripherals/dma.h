/* 
 * File:   dma.h
 * Author: Jennyston
 *
 * Created on January 10, 2017, 8:51 PM
 */

#ifndef DMA_H
#define	DMA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define DMA_INTERRUPT_PRIORITY 5

    void InitDMA(volatile unsigned int *sourceAddress,
            unsigned char *destinationAddress, unsigned short destinationSize);


#ifdef	__cplusplus
}
#endif

#endif	/* DMA_H */

