/*
 * UART_Driver.c
 *
 *  Created on: Nov 9, 2016
 *      Author: mac
 */


#include "derivative.h"
#include "UART_Driver.h"



void UART_vfnInit(void)
{
	NVIC_ISER |= (1<<12);
	//unsigned short Divisor;
	
	/*Clock enabled for PORTA*/
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	
	/*Clock enabled for UART1*/
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	
	/* UART0 clock source select / Selects the clock source for the UART0 transmit and receive clock. Pag 196*/
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);
	
	/* 21 Mhz Baud Clock
		PLL/FLL clock select
		Selects the MCGPLLCLK or MCGFLLCLK clock for various peripheral clocking options.
		0 MCGFLLCLK clock  PAG 196 RM 
	*/
	
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK;
	
	/*Direction of UART1 to PTA15*/
	/*ALT3 for UART1_Rx*/
	PORTA_PCR1 = PORT_PCR_MUX(2);
	
	/*Direction of UART1 to PTA14*/
	/*ALT3 for UART1_Tx*/
	PORTA_PCR2 = PORT_PCR_MUX(2);
	
	/*Stop Bit*/
	UART0_BDH |= UART0_BDH_SBNS_MASK;	
	
	/* Ponemos el OSR como 32 bits */
	UART0_C4 = UART0_C4_OSR(0x1F);
			
	/* UART 0 Receiver and transmitter use 8-bit data characters. write a 0*/
	UART0_C1  &= ~UART0_C1_M_MASK;
	
	/*Bauld Rate High*/
	UART0_BDH &= ~UART0_BDH_SBR_MASK;
	
	/* Utilizaremos Baud Rate de 68 para tener un 9600 */
	/* La formula es : Baud Clock / (OSR + 1) * BR */
	/*                 21MHz     /  (31  + 1) * 68 = 9600 */
	
	UART0_BDL = BR;
	UART0_C2 |= UART0_C2_RIE_MASK;
}

void UART_vfnRrx (void){
	
	 UART0_C2 &= ~UARTLP_C2_TE_MASK;
	 UART0_C2 |= UARTLP_C2_RE_MASK;
}

void UART_vfnTrx (void){
	
	UART0_C2 |= UARTLP_C2_TE_MASK;
	UART0_C2 &= ~UARTLP_C2_RE_MASK;
}

void UART_vfnUartDataTransmit(unsigned char bDataOut)
{
	if( UART0_S1 & UART_S1_TDRE_MASK )
	{
		UART0_D |= bDataOut;	
	}
}


void UART0_IRQHandler()
{		
	if((UART0_S1 & UART0_S1_RDRF_MASK )){
		bDatIN  = UART0_D;	
		UartRxFlag = TRUE;
	}
}
