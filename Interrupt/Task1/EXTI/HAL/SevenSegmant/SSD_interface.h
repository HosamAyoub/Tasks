/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: Seven Segment			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define ANODE 		0
#define CATHODE 	1

typedef struct
{
	u8 u8CommonType;
	u8 u8Port;
	u8 u8EnablePort;
	u8 u8EnablePin;
}SSD_t;

u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t *Copy_pSSD_tElements);

#endif
