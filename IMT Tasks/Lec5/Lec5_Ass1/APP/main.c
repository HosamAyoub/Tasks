/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#define OUTPUT_PINS 	0b11000011
#define PRESSED			0
#define NOT_PRESSED		1

void main (void)
{
	u8 pin6, pin7;
	LCD_voidInitialize();
	DIO_u8SetPortDirection(DIO_PORTA, OUTPUT_PINS);
	DIO_u8SetPinValue(DIO_PORTA, DIO_PIN6, DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA, DIO_PIN7, DIO_PIN_HIGH);
	LCD_voidSendString("Sleep Mode");

	while (1)
	{
		/*Getting the pins value from the tactile switches*/
		DIO_u8GetPinValue(DIO_PORTA, DIO_PIN6, &pin6);
		DIO_u8GetPinValue(DIO_PORTA, DIO_PIN7, &pin7);
		/*Rotating the motor ClockWise*/
		if ((pin6 == PRESSED) && (pin7 == NOT_PRESSED))
		{
			MOTOR_voidClockWise();
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("Clockwise");
		}
		/*Rotating the motor CounterClockWise*/
		else if ((pin6 == NOT_PRESSED) && (pin7 == PRESSED))
		{
			MOTOR_voidCounterClockWise();
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("CounterClockwise");
		}
		/*Going to motor sleep mode*/
		else if ((pin6 == PRESSED) && (pin7 == PRESSED))
		{
			MOTOR_voidStop();
			LCD_voidSendCommand(LCD_CLEAR);
			LCD_voidSendString("Sleep Mode");
			_delay_ms(250);
		}
	}
}
