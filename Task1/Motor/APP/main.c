/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/Motor/MOTOR_interface.h"

void main (void)
{
	MOTOR_voidInitialize();
	while (1)
	{
		MOTOR_voidClockWise();
		_delay_ms(2000);
		MOTOR_voidStop();
		_delay_ms(2000);
		MOTOR_voidCounterClockWise();
		_delay_ms(2000);
		MOTOR_voidStop();
		_delay_ms(2000);
	}
}
