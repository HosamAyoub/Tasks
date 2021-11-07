/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"

void main(void)
{
	u8 Local_u8Row = 0, Local_u8Column = 0;
	LCD_voidInitialize();
	while (1)
	{
		for (Local_u8Column = 0; Local_u8Column < 14; Local_u8Column += 2)
		{
			LCD_voidGoToXY(Local_u8Row, Local_u8Column);
			LCD_voidSendString("Hosam");
			_delay_ms(250);
			LCD_voidSendCommand(0x01);
			Local_u8Row ^= 1;
		}
	}
}
