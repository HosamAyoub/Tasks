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

void (*Global_pvInt0NotifcationFunction)(void) = NULL;
void (*Global_pvInt1NotifcationFunction)(void) = NULL;
void (*Global_pvInt2NotifcationFunction)(void) = NULL;


void EXTI_voidInit (void)
{
	#if	EXTI_INT0_ENALBE == ENABLE
		SET_BIT(GICR, GICR_INT0);
		#if	EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		#else
			#error "EXTI_INT0_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT0_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT0);
	#else
		#error "EXTI_INT0_ENALBE Error Configuration"
	#endif


	#if	EXTI_INT1_ENALBE == ENABLE
		SET_BIT(GICR, GICR_INT1);
		#if	EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		#else
			#error "EXTI_INT1_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT1_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT1);
	#else
		#error "EXTI_INT1_ENALBE Error Configuration"
	#endif


	#if	EXTI_INT2_ENALBE == ENABLE
		SET_BIT(GICR, GICR_INT2);
		#if EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
		#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCSR, MCUCSR_ISC2);
		#else
			#error "EXTI_INT2_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT2_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT2);
	#else
		#error "EXTI_INT2_ENALBE Error Configuration"
	#endif
}


void EXTI_voidSetInt0SenseControl (u8 Copy_u8SenseControl)
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


void EXTI_voidInt0SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	Global_pvInt0NotifcationFunction = Copy_pvNotificationFunction;
}

/*ISR for INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (Global_pvInt0NotifcationFunction != NULL)
	{
		Global_pvInt0NotifcationFunction();
	}
	else
	{

	}
}

void EXTI_voidInt1SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	Global_pvInt1NotifcationFunction = Copy_pvNotificationFunction;
}

/*ISR for INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (Global_pvInt1NotifcationFunction != NULL)
	{
		Global_pvInt1NotifcationFunction();
	}
	else
	{

	}
}

void EXTI_voidInt2SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	Global_pvInt2NotifcationFunction = Copy_pvNotificationFunction;
}

/*ISR for INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (Global_pvInt2NotifcationFunction != NULL)
	{
		Global_pvInt2NotifcationFunction();
	}
	else
	{

	}
}
