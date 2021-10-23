/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define FALLING_EDGE	0
#define RISING_EDGE		1
#define LOW_LEVEL		2
#define ON_CHANGE		3

void EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl);
void EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl);
void EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl);

#endif
