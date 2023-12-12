/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB.c
 * @author         : Ahmed Naeim
 * @brief          : Contains static code to control System Control Block
 ******************************************************************************
**/

#include "CortexM3/CortexM3_Core_SCB.h"


/*
 * Brief:	Set Priority Grouping
 * Details:	Sets Priority Grouping using the required unlock sequence.
 * 			the parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
 * 			only values from 0 to 7 are used.
 * 			in case of conflict between priority group and available
 * param[in]: PriorityGroup -> priority grouping field
 * */
void SCB_SetPriorityGrouping(uint32_t PriorityGroup)
{
	uint32_t Register_Value=0;																/* will include the final value to assign in SCB-> AIRCR */
	uint32_t PriorityGroupTemp= ((uint32_t)PriorityGroup & (uint32_t)0x07); 				/* To secure that bit 3 to 7 are 0 even if the user set them by mistake */

	Register_Value= SCB-> AIRCR;															/* Read the current value and take a copy */
	Register_Value &= ~((uint32_t) SCB_AIRCR_PRIGROUP_MSK | SCB_AIRCR_VERCTKEYSTAT_MSK); 	/* using the 1 (Set) masks and ~ them to make the unused bits = 0 for safety */

	Register_Value= (Register_Value | ((uint32_t) 0x05FA << SCB_AIRCR_VERCTKEYSTAT_Pos) |
						(PriorityGroupTemp << SCB_AIRCR_PRIGROUP_Pos));						/* The Mathematical Function */
	SCB-> AIRCR = Register_Value;		 													/* No need for return because it is already pointer to struct that modify the value in this address */
}


/*
 * Brief:	Get Priority Grouping
 * Details:	Reads Group Priority Group filed from the NVIC Interrupt Controller
 * return: Priority Grouping Field SCB->AIRCR [10:8] PRIGROUP field
 * */
uint32_t SCB_GetPriorityGrouping(void)
{
	return ((SCB->AIRCR & SCB_AIRCR_PRIGROUP_MSK) >> SCB_AIRCR_PRIGROUP_Pos);
}
