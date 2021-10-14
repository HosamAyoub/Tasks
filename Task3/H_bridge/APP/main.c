/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/H_Bridge/H_Bridge_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void main (void)
{
	H_Bridge_voidIntialization();
	while (1)
	{
		H_Bridge_voidFirstDirection();
		_delay_ms(2000);
		H_Bridge_voidStop();
		_delay_ms(1000);
		H_Bridge_voidSecondDirection();
		_delay_ms(2000);
		H_Bridge_voidStop();
		_delay_ms(1000);
	}
}
