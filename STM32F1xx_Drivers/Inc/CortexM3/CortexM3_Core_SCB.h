/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB.h
 * @author         : Ahmed Naeim
 * @brief          : Contains declaration to control System Control Block
 ******************************************************************************
**/


#ifndef CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORE_SCB_H_

/*----------------------------------------------Includes Start--------------------------------------------*/
#include "Common/STD_Types.h"
/*-----------------------------------------------Includes End---------------------------------------------*/


/*-------------------------------------------Macros Declaration Start-------------------------------------*/

/* Memory Mapping of Core Hardware */
#define SCB_BASE					(0xE000ED00UL)							/*<! System Control Block Base Address */
#define SCB							((SCB_Type *) 0xE000ED00UL)				/*<! Pointer to SCB-Type to access all registers in it */

/* @defgroup CORTEX-M3 Preemption Periority Groups */
#define SCB_PRIORITYGROUP_0			0x00000007U 		/*<! 0 bit for Pre-Empition
															 4 bits for Sub-Priority*/
#define SCB_PRIORITYGROUP_1			0x00000006U 		/*<! 1 bit for Pre-Empition
															 3 bits for Sub-Priority*/
#define SCB_PRIORITYGROUP_2			0x00000005U 		/*<! 2 bit for Pre-Empition
															 2 bits for Sub-Priority*/
#define SCB_PRIORITYGROUP_3			0x00000004U 		/*<! 3 bit for Pre-Empition
															 1 bits for Sub-Priority*/
#define SCB_PRIORITYGROUP_4			0x00000003U 		/*<! 4 bit for Pre-Empition
															 0 bits for Sub-Priority*/

#define SCB_AIRCR_PRIGROUP_Pos				8U					/*<! SCB AIRCR: PRIGROP Position */
#define SCB_AIRCR_PRIGROUP_MSK				(7UL << SCB_AIRCR_PRIGROUP_Pos)		/* Mask to set bits with 0b111 */

#define SCB_AIRCR_VERCTKEYSTAT_Pos			16U					/*<! SCB AIRCR: VERCTKEYSTAT Position */
#define SCB_AIRCR_VERCTKEYSTAT_MSK			(0xFFFFUL << SCB_AIRCR_VERCTKEYSTAT_Pos)		/* Mask to set bits with 0xFFFF */


/*--------------------------------------------Macros Declaration End--------------------------------------*/



/*--------------------------------------Macros Functions Declaration Start--------------------------------*/

/*---------------------------------------Macros Functions Declaration End---------------------------------*/



/*-----------------------------------------Data Type Declaration Start------------------------------------*/
typedef struct
{
	volatile uint32_t CPUID;			/*<! offset: 0x000 (R/ ) */
	volatile uint32_t ICSR;				/*<! offset: 0x004 (R/W) */
	volatile uint32_t VTOR;				/*<! offset: 0x008 (R/W) */
	volatile uint32_t AIRCR;			/*<! offset: 0x00C (R/W) */
	volatile uint32_t SCR;				/*<! offset: 0x010 (R/W) */
	volatile uint32_t CCR;				/*<! offset: 0x014 (R/W) */
	volatile uint32_t SHPR1;			/*<! offset: 0x018 (R/W) */
	volatile uint32_t SHPR2;			/*<! offset: 0x01C (R/W) */
	volatile uint32_t SHPR3;			/*<! offset: 0x020 (R/W) */
	volatile uint32_t SHCRS;			/*<! offset: 0x024 (R/W) */
	volatile uint32_t CFSR;				/*<! offset: 0x028 (R/W) */

}SCB_Type;
/*------------------------------------------Data Type Declaration End-------------------------------------*/



/*-------------------------------------Software Interfaces Declaration Start------------------------------*/

/*
 * Brief:	Set Priority Grouping
 * Details:	Sets Priority Grouping using the required unlock sequence.
 * 			the parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
 * 			only values from 0 to 7 are used.
 * 			in case of conflict between priority group and available
 * param[in]: PriorityGroup -> priority grouping field
 * */
void SCB_SetPriorityGrouping(uint32_t PriorityGroup);


/*
 * Brief:	Get Priority Grouping
 * Details:	Reads Group Priority Group filed from the NVIC Interrupt Controller
 * return: Priority Grouping Field SCB->AIRCR [10:8] PRIGROUP field
 * */
uint32_t SCB_GetPriorityGrouping(void);


/*--------------------------------------Software Interfaces Declaration End-------------------------------*/


#endif /* CORTEXM3_CORE_SCB_H_ */
