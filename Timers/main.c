/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "main.h"

void main (void)
{
	u16 Local_u16Reading;
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	ADC_voidInit();
	TIMERS_voidInit();
	while (1)
	{
		Local_u16Reading = ADC_u16GetChannelReadingSynchronous(ADC_CHANNEL0);
		TIMERS_voidTimer0SetCompareMatchValue(Local_u16Reading);
	}
}
