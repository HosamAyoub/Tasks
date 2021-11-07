#include "avr/io.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "STD_TYPES.h"

int main(void)
{
	s8 Local_s8iterator1, Local_s8iterator2;
	u8 Local_u8counter = 0, Local_u8ArrayDecToSeg[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001,
														 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};

	DDRA = 0xFF;
	DDRC = 0xFF;
	DDRB = 0x07;

	while (1)
	{
		/*Turning on Green LED for 15 seconds*/
		PORTB = 1;
		for(Local_s8iterator1 = 1; Local_s8iterator1 >= 0; Local_s8iterator1--)
		{
			for (Local_s8iterator2 = 5; Local_s8iterator2 >= 0; Local_s8iterator2--)
			{
				if (Local_s8iterator1 == 0 && Local_u8counter == 0)
				{
					Local_s8iterator2 = 9;
					Local_u8counter++;
				}
				PORTC = Local_u8ArrayDecToSeg[Local_s8iterator1];
				PORTA = Local_u8ArrayDecToSeg[Local_s8iterator2];
				_delay_ms(300);
			}
		}

		/*Turning on Yellow LED for 7 seconds and resetting the counter*/
		PORTB = 2;
		Local_u8counter = 0;

		for(Local_s8iterator1 = 7; Local_s8iterator1 >= 0; Local_s8iterator1--)
		{
			Local_s8iterator2 = 0;
			PORTC = Local_u8ArrayDecToSeg[Local_s8iterator2];
			PORTA = Local_u8ArrayDecToSeg[Local_s8iterator1];
			_delay_ms(300);
		}

		/*Turning on Red LED for 15 seconds and resetting the counter*/
		Local_u8counter = 0;
		PORTB = 4;

		for(Local_s8iterator1 = 1; Local_s8iterator1 >= 0; Local_s8iterator1--)
		{
			for (Local_s8iterator2 = 5; Local_s8iterator2 >= 0; Local_s8iterator2--)
			{
				if (Local_s8iterator1 == 0 && Local_u8counter == 0)
				{
					Local_s8iterator2 = 9;
					Local_u8counter++;
				}
				PORTC = Local_u8ArrayDecToSeg[Local_s8iterator1];
				PORTA = Local_u8ArrayDecToSeg[Local_s8iterator2];
				_delay_ms(300);
			}
		}

		/*Turning on Yellow LED for 7 seconds and resetting the counter*/
		PORTB = 2;
		Local_u8counter = 0;

		for(Local_s8iterator1 = 7; Local_s8iterator1 >= 0; Local_s8iterator1--)
		{
			Local_s8iterator2 = 0;
			PORTC = Local_u8ArrayDecToSeg[Local_s8iterator2];
			PORTA = Local_u8ArrayDecToSeg[Local_s8iterator1];
			_delay_ms(300);
		}

		Local_u8counter = 0;

	}
	return 0;
}
