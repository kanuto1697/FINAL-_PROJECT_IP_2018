/*
 * PIT_Driver.c
 *
 *  Created on: Oct 6, 2016
 *      Author: mac
 */


#include "derivative.h"
#include "PIT_Driver.h"




void PIT_vfnDriverInit(long MyLdValue)
{
	NVIC_ISER |= PIT_INTERRUPT_VECTOR;
	/*Clock's PIT is enabled*/
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	/*Clock for standard PIT timers is enabled*/
	/*Timers continue to run in Debug mode*/
	PIT_MCR = FALSE;
	/*Assigning time on pit_ldval*/
	PIT_LDVAL1 |= MyLdValue;
	/*Interrupt will be requested whenever TIF is set*/
	PIT_TCTRL1 |= PIT_TCTRL_TIE_MASK;
	/*Timer n is enabled*/
	PIT_TCTRL1 |= PIT_TCTRL_TEN_MASK;	
}

void PIT_IRQHandler()
{
	PITFlag = TRUE;
	PIT_TFLG1 |= PIT_TFLG_TIF_MASK;
}
