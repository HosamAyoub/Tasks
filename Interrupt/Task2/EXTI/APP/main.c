/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "main.h"
#define S	0b10010001

void ToggleLED1 (void);
void ToggleLED2 (void);
void ToggleLED3 (void);

void main (void)
{
	DIO_u8SetPortDirection(DIO_PORTA, S);
	LCD_voidInitialize();
	LCD_voidSendCommand(0x01);
	LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN0);
	LCD_voidSendString("LED1");
	LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN6);
	LCD_voidSendString("LED2");
	LCD_voidGoToXY(LCD_ROW0, LCD_COLUMN12);
	LCD_voidSendString("LED3");
	LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN1);
	LCD_voidSendString("OFF");
	LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN7);
	LCD_voidSendString("OFF");
	LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN13);
	LCD_voidSendString("OFF");
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PULLUP);
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN3, DIO_PULLUP);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN2, DIO_PULLUP);
	EXTI_voidInt0SetCallBack(&ToggleLED1);
	EXTI_voidInt1SetCallBack(&ToggleLED2);
	EXTI_voidInt2SetCallBack(&ToggleLED3);
	GIE_voidEnableGlobalInterrupt();
	EXTI_voidInit();
	while (1)
	{

	}
}

void ToggleLED1 (void)
{
	/*Toggle LED*/
	u8 Local_u8PinState;
	DIO_u8TogglePin(DIO_PORTA, DIO_PIN0);
	DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0, &Local_u8PinState);
	if (Local_u8PinState == 0)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN1);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN1);
		LCD_voidSendString("OFF");
	}
	else if (Local_u8PinState == 1)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN1);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN1);
		LCD_voidSendString("ON");
	}
}

void ToggleLED2 (void)
{
	/*Toggle LED*/
	u8 Local_u8PinState;
	DIO_u8TogglePin(DIO_PORTA, DIO_PIN4);
	DIO_u8GetPinValue(DIO_PORTA, DIO_PIN4, &Local_u8PinState);
	if (Local_u8PinState == 0)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN7);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN7);
		LCD_voidSendString("OFF");
	}
	else if (Local_u8PinState == 1)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN7);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN7);
		LCD_voidSendString("ON");
	}
}

void ToggleLED3 (void)
{
	/*Toggle LED*/
	u8 Local_u8PinState;
	DIO_u8TogglePin(DIO_PORTA, DIO_PIN7);
	DIO_u8GetPinValue(DIO_PORTA, DIO_PIN7, &Local_u8PinState);
	if (Local_u8PinState == 0)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN13);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN13);
		LCD_voidSendString("OFF");
	}
	else if (Local_u8PinState == 1)
	{
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN13);
		LCD_voidSendString("   ");
		LCD_voidGoToXY(LCD_ROW1, LCD_COLUMN13);
		LCD_voidSendString("ON");
	}
}


