#include "avr/io.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

int main(void)
{
	u8 Local_u8Shift [8] 	= {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	u8 Local_u8Converg [4] 	= {0x81, 0x42, 0x24, 0x18};
	u8 Local_u8Sneak [15] 	= {0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff,
						   	   0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80};
	s8 Local_s8Counter = 0;
	DDRA  = 0xff;
	PORTA = 0x00;
	DDRB  = 0x00;
	PORTB = 0xff;

	while(1)
	{
		/*Flashing LEDs every 500ms*/
		if(GET_BIT(PINB, 0) == 0)
		{
			PORTA = ~PORTA;
			_delay_ms(500);
		}
		/*Shifting Left LEDs every 250ms*/
		else if(GET_BIT(PINB, 1) == 0)
		{
			for(Local_s8Counter = 0; Local_s8Counter < 8; Local_s8Counter++)
			{
				PORTA = Local_u8Shift[Local_s8Counter];
				_delay_ms(250);
			}
		}
		/*Shifting Right LEDs every 250ms*/
		else if(GET_BIT(PINB, 2) == 0)
		{
			for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
			{
				PORTA = Local_u8Shift[Local_s8Counter];
				_delay_ms(250);
			}
		}
		/*Converging 2-LEDs every 300ms*/
		else if(GET_BIT(PINB, 3) == 0)
		{
			for(Local_s8Counter = 0; Local_s8Counter < 4; Local_s8Counter++)
			{
				PORTA = Local_u8Converg[Local_s8Counter];
				_delay_ms(300);
			}
		}
		/*Diverging 2-LEDs every 300ms*/
		else if(GET_BIT(PINB, 4) == 0)
		{
			for(Local_s8Counter = 3; Local_s8Counter >= 0; Local_s8Counter--)
			{
				PORTA = Local_u8Converg[Local_s8Counter];
				_delay_ms(300);
			}
		}
		/*Ping-pong effect every 250ms*/
		else if(GET_BIT(PINB, 5) == 0)
		{
			for(Local_s8Counter = 0; Local_s8Counter < 8; Local_s8Counter++)
			{
				PORTA = Local_u8Shift[Local_s8Counter];
				_delay_ms(250);

				if(Local_s8Counter == 7)
				{
					for(Local_s8Counter = 6; Local_s8Counter >= 0; Local_s8Counter--)
					{
						PORTA = Local_u8Shift[Local_s8Counter];
						_delay_ms(250);
						if(GET_BIT(PINB, 5) == 1)
						{
							break;
						}
					}
					Local_s8Counter = 0;
				}
				if(GET_BIT(PINB, 5) == 1)
				{
					break;
				}
			}
		}
		/*Snake effect every 300ms*/
		else if(GET_BIT(PINB, 6) == 0)
		{
			for(Local_s8Counter = 0; Local_s8Counter < 15; Local_s8Counter++)
			{
				PORTA = Local_u8Sneak[Local_s8Counter];
				_delay_ms(300);

				if(Local_s8Counter == 14)
				{
					for(Local_s8Counter = 13; Local_s8Counter >= 0; Local_s8Counter--)
					{
						PORTA = Local_u8Sneak[Local_s8Counter];
						_delay_ms(300);
						if(GET_BIT(PINB, 6) == 1)
						{
							break;
						}
					}
					Local_s8Counter = 0;
				}

				if(GET_BIT(PINB, 6) == 1)
				{
					break;
				}
			}
		}
		/*2-LEDs Converging/Diverging every 300ms*/
		else if(GET_BIT(PINB, 7) == 0)
		{
			for(Local_s8Counter = 0; Local_s8Counter < 4; Local_s8Counter++)
			{
				PORTA = Local_u8Converg[Local_s8Counter];
				_delay_ms(300);

				if(Local_s8Counter == 3)
				{
					for(Local_s8Counter = 2; Local_s8Counter >= 0; Local_s8Counter--)
					{
						PORTA = Local_u8Converg[Local_s8Counter];
						_delay_ms(300);
						if(GET_BIT(PINB, 7) == 1)
						{
							break;
						}
					}
					Local_s8Counter = 0;
				}
				if(GET_BIT(PINB, 7) == 1)
				{
					break;
				}
			}
		}
		/*if there is no pressed switch*/
		else
		{
			PORTA = 0;
		}
	}
	return 0;
}
