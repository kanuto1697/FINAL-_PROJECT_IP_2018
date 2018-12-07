/*
 * ADC_Init.c
 *
 *  Created on: Jul 31, 2017
 *      Author: Dany_Eusebio
 */

#include "ADC_Init.h"
#include <derivative.h>

void vfnInitAdc(void)
{
	  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	  SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;  
	  PORTE_PCR20 = PORT_PCR_MUX(0);
	  ADC0_CFG1 = 0x00; 
	  ADC0_CFG2 = 0x00;    
	  ADC0_SC2 = 0x00;      
	  ADC0_SC3 = 0x80;    
	  ADC0_SC1A = 0x00;
}

uint8_t wfnMuestraAdc (void)
{
	uint8_t bResultado=0;
	
	if((ADC0_SC1A & ADC_SC1_COCO_MASK )== ADC_SC1_COCO_MASK)
	{
		bResultado= ADC0_RA;	
	}
	
	else
	{
		bResultado=0;
	}
	
	return bResultado;
}
