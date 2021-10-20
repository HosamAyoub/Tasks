/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LED					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_u8TurnOn(LED_t *Copy_LED_tElements)
{
	if(Copy_LED_tElements->u8ConnectionType == SOURCE)
	{
		DIO_u8SetPinDirection(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_HIGH);
	}
	else if(Copy_LED_tElements->u8ConnectionType == SINK)
	{
		DIO_u8SetPinDirection(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_LOW);
	}
	else
	{
		return;
	}
}

void LED_u8TurnOff(LED_t *Copy_LED_tElements)
{
	if(Copy_LED_tElements->u8ConnectionType == SOURCE)
	{
		DIO_u8SetPinDirection(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_LOW);
	}
	else if(Copy_LED_tElements->u8ConnectionType == SINK)
	{
		DIO_u8SetPinDirection(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_LED_tElements->u8Port, Copy_LED_tElements->u8Pin, DIO_PIN_HIGH);
	}
	else
	{
		return;
	}
}
