/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../DIO/DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
	case LOW_LEVEL:
	{
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;
	}
	case ON_CHANGE:
	{
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;
	}
	case FALLING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;
	}
	case RISING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;
	}
	default:
	{
		break;
	}
	}
	SET_BIT(GICR, GICR_INT0);
}

void EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
	case LOW_LEVEL:
	{
		CLR_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case ON_CHANGE:
	{
		CLR_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case FALLING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case RISING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	default:
	{
		break;
	}
	}
	SET_BIT(GICR, GICR_INT1);
}

void EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
	case FALLING_EDGE:
	{
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	}
	case RISING_EDGE:
	{
		SET_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	}
	default:
	{
		break;
	}
	}
	SET_BIT(GICR, GICR_INT2);
}


/*ISR for INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	/*Toggle LED*/
	DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
	_delay_ms(500);
	DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
}
