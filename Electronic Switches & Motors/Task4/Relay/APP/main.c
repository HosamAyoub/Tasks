/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/Relay/Relay_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void main (void)
{
	Relay_voidIntialization();
	while (1)
	{
		Relay_voidNormallyClose();
		_delay_ms(2000);
		Relay_voidNormallyOpen();
		_delay_ms(2000);
	}
}
