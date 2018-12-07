/*
 * PIT_Driver.h
 *
 *  Created on: Oct 6, 2016
 *      Author: mac
 */

#ifndef PIT_DRIVER_H_
#define PIT_DRIVER_H_


/*!
 \def      FALSE
 \brief    A cero value
 */
#define FALSE                   0

/*!
 \def      TRUE
 \brief    A one value
 */
#define TRUE					1

/*!
 \def      PIT_INTERRUPT_VECTOR
 \brief    NVIC vector
 */
#define PIT_INTERRUPT_VECTOR 	(1<<22)

/*!
 \var      PITFlag
 \brief    The flag of the PIT
 */
volatile unsigned char PITFlag;

/*!
 \fn       PIT_vfnDriverInit(void)
 \param    MyLdValue Time you want PIT 
 \return   No return
 \brief    Initialization of PIT
 */
void PIT_vfnDriverInit(long);

/*!
 \fn       PIT_IRQHandler(void)
 \param    void
 \return   No return
 \brief    The function for the interrupt
 */
void PIT_IRQHandler(void);



#endif /* PIT_DRIVER_H_ */
