/*
 * UART_Driver.h
 *
 *  Created on: Nov 9, 2016
 *      Author: mac
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_



/*!
 \def      BR
 \brief    Baud Rate value
 */
#define BR       0x44

/*!
 \def      TRUE
 \brief    A 1 Logic
 */
#define TRUE     1
/*!
 \def      FALSE
 \brief     A 0 Logic
 */
#define FALSE    0

/*!
 \var      UartRxFlag
 \brief    uart rx flag
 */
volatile unsigned char UartRxFlag;
/*!
 \var      bDatIN
 \brief    the value of the uartRX
 */
volatile unsigned char bDatIN;
/*!
 \fn       UART_vfnInit(void)
 \param    void
 \return   No return
 \brief    Initialization of UART
 */
void UART_vfnInit(void);
/*!
 \fn       void UART_vfnUartDataTransmit(unsigned char bDataOut);
 \param    bDataOut gave the data to send
 \return   No return
 \brief    gave the parameter to send to the register D
 */
void UART_vfnUartDataTransmit(unsigned char bDataOut);
/*!
 \fn       void UART0_IRQHandler(void);
 \param    void
 \return   No return
 \brief    Recive the data to send
 */
void UART0_IRQHandler(void);
/*!
 \fn       void UART_vfnTrx (void);
 \param    void
 \return   No return
 \brief    Initialization of UARTrx
 */
void UART_vfnTrx (void);
/*!
 \fn       void UART_vfnRrx (void);
 \param    void
 \return   No return
 \brief    Initialization of UARTrc
 */
void UART_vfnRrx (void);



#endif /* UART_DRIVER_H_ */
