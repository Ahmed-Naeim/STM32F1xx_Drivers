/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Naeim
 * @brief          : Contains the Static Code to control NVIC
 ******************************************************************************
**/

#include "CortexM3/CortexM3_Core_NVIC.h"



/*******	CMSIS Functions	********/

/*
 * Brief		Enables an interrupt or exception
 * Details
 * param[in]	IRQn-> device specific interrupt number
 * note			IRQn MUST be not negative
 * */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >= 0)
	{
		NVIC-> ISER[((uint32_t) IRQn) >> 5]		=	(1UL << (((uint32_t) IRQn) & 0x1F));

	}

}

/*
 * Brief		Disables an interrupt or exception
 * Details
 * param[in]	IRQn-> device specific interrupt number
 * note			IRQn MUST be not negative
 * */
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >= 0)
	{
		NVIC-> ICER[((uint32_t) IRQn) >> 5]		=	(1UL << (((uint32_t) IRQn) & 0x1F));

	}

}

/*
 * Brief		Sets the pending status of interrupt or exception to 1
 * Details		Sets the pending bit for the device specific interrupt number
 * param[in]	IRQn-> device specific interrupt number
 * note			IRQn MUST be not negative
 * */
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >= 0)
	{
		NVIC-> ISPR[((uint32_t) IRQn) >> 5]		=	(1UL << (((uint32_t) IRQn) & 0x1F));

	}

}

/*
 * Brief		Clears the pending status of interrupt or exception to 0
 * Details		Clears the pending bit for the device specific interrupt number
 * param[in]	IRQn-> device specific interrupt number
 * note			IRQn MUST be not negative
 * */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >= 0)
	{
		NVIC-> ICPR[((uint32_t) IRQn) >> 5]		=	(1UL << (((uint32_t) IRQn) & 0x1F));

	}

}

/*
 * Brief		Get Active Interrupt
 * Details		Read the active register in the NVIC and returns the active bit for the device specific interrupt number
 * param[in]	IRQn-> device specific interrupt number
 * return		0-> interrupt service is not active
 * return		1->	interrupt service is  active
 * note			IRQn MUST be not negative
 * */
uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >=0)
	{
		return ((NVIC-> IABR[((uint32_t) IRQn) >> 5]	& (1UL << (((uint32_t) IRQn) & 0x1F))) != (uint32_t) 0 ) ? 1UL : 0UL;
	}
	else{
		return 0;
	}

}


/*
 * Brief		Set priority for IRQn
 * Details		Read the active register in the NVIC and returns the active bit for the device specific interrupt number
 * return		IRQn -> Interrupt Number
 * 				priority -> priority to set
 * note			Priority can't be set for every processor exception
 * */
void NVIC_SetPriority (IRQn_Type IRQn, uint32_t priority)
{
	if ((uint32_t) IRQn >=0)
	{
		NVIC->IP[(uint32_t) IRQn] = (uint8_t) ((priority << (8-NVIC_PRIO_BITS)) & (uint32_t) 0xFF);

	}
	else{
		/* Nothing */
	}

}


/*
 * Brief		Read priority of IRQn
 * Details		Reads the priority for the device specific interrupt number or a processor exception.
 * 				The interrupt can be positie to specify the a device specific Interrupt
 * 				or negative to specify processor exception.
 * param[in]	IRQn -> Interrupt Number
 * return		Interrupt Priority
 * 				Value is aligned automatically to the implemented priority bits of microcontroller
 * return		1->	interrupt service is  active
 * note			IRQn MUST be not negative
 * */
uint32_t NVIC_GetPriority (IRQn_Type IRQn)
{
	if ((uint32_t) IRQn >=0)
	{
		return ((NVIC->IP[(uint32_t) IRQn]) >> (8-NVIC_PRIO_BITS));
	}
	else{

	}
	return 0;

}
