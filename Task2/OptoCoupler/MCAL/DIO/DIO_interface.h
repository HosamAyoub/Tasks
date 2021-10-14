/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PIN_INPUT		0
#define DIO_PIN_OUTPUT	    1

#define DIO_PIN_LOW		    0
#define DIO_PIN_HIGH	    1

#define DIO_PORTA		    0
#define DIO_PORTB		    1
#define DIO_PORTC		    2
#define DIO_PORTD		    3

#define DIO_PIN0		    0
#define DIO_PIN1		    1
#define DIO_PIN2		    2
#define DIO_PIN3		    3
#define DIO_PIN4		    4
#define DIO_PIN5		    5
#define DIO_PIN6		    6
#define DIO_PIN7		    7

#define DIO_NO_PULLUP	    0
#define DIO_PULLUP		    1

#define DIO_PORT_INPUT	    0
#define DIO_PORT_OUTPUT	    0xff

#define DIO_PORT_LOW	    0
#define DIO_PORT_HIGH	    0xff

#define DIO_OK				0
#define DIO_ERROR			1


u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_u8Variable);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8Variable);


#endif
