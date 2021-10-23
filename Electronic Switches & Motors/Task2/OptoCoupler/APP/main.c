/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/OptoCoupler/OptoCoupler_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void main (void)
{
	OptoCoupler_voidIntialization();
	while (1)
	{
		OptoCoupler_voidOnMode();
		_delay_ms(1000);
		OptoCoupler_voidOffMode();
		_delay_ms(1000);
	}
}
