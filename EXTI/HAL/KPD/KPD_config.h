/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: KPD					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_COLUMNS_PORT		DIO_PORTA
#define KPD_COLUMN0_PIN			DIO_PIN3
#define KPD_COLUMN1_PIN			DIO_PIN2
#define KPD_COLUMN2_PIN	        DIO_PIN1
#define KPD_COLUMN3_PIN	        DIO_PIN0

#define KPD_ROWS_PORT			DIO_PORTA
#define KPD_ROW0_PIN			DIO_PIN4
#define KPD_ROW1_PIN	        DIO_PIN5
#define KPD_ROW2_PIN	        DIO_PIN6
#define KPD_ROW3_PIN	        DIO_PIN7

#define KPD_KEYS_ARRAYS_VALUES	{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}}

#define KPD_NO_PRESSED_KEY		0xAA


#endif
