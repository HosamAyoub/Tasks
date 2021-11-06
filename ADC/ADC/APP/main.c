/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "main.h"

void main (void)
{
	u16 Local_u16Reading;
	DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	DIO_u8SetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT);
	ADC_voidInit();
	LCD_voidInitialize();
	while (1)
	{
		Local_u16Reading = ADC_u8GetChannelReadingSynchronous(CHANNEL0);
		if (Local_u16Reading <= 100)
		{
			LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
			LCD_voidSendString("8 LEDs are on");
			DIO_u8SetPortValue(DIO_PORTB, DIO_PORT_HIGH);
		}
		else if ((Local_u16Reading > 100) && (Local_u16Reading <= 200))
		{
			LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
			LCD_voidSendString("6 LEDs are on");
			DIO_u8SetPortValue(DIO_PORTB, SIX_LEDS);
		}
		else if ((Local_u16Reading > 200) && (Local_u16Reading <= 350))
		{
			LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
			LCD_voidSendString("4 LEDs are on");
			DIO_u8SetPortValue(DIO_PORTB, FOUR_LEDS);
		}
		else if ((Local_u16Reading > 350) && (Local_u16Reading <= 500))
		{
			LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
			LCD_voidSendString("2 LEDs are on");
			DIO_u8SetPortValue(DIO_PORTB, TWO_LEDS);
		}
		else if ((Local_u16Reading > 700) && (Local_u16Reading <= 1000))
		{
			LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
			LCD_voidSendString("0 LEDs are on");
			DIO_u8SetPortValue(DIO_PORTB, DIO_PORT_LOW);
		}
	}

}
