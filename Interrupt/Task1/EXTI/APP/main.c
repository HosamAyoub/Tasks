/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void main (void)
{
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PULLUP);
	EXTI_voidSetInt0SenseControl(FALLING_EDGE);
	GIE_voidEnableGlobalInterrupt();
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	while (1)
	{

	}
}


