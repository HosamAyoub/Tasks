/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/Transistor/Transistor_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void main(void)
{
	Transisor_voidIntialization();

	while (1)
	{
		Transisor_voidSaturationMode();
		_delay_ms(1000);
		Transisor_voidCutOffMode();
		_delay_ms(1000);
	}
}
