/**
 ******************************************************************************
 * @file           : CortexM3_Core_SysTick.h
 * @author         : Ahmed Naeim
 * @brief          : Contains declaration to control SysTick Timer
 ******************************************************************************
**/

#ifndef CORTEXM3_CORTEXM3_CORE_SYSTICK_H_
#define CORTEXM3_CORTEXM3_CORE_SYSTICK_H_


/*----------------------------------------------Includes Start--------------------------------------------*/
#include "Common/STD_Types.h"
#include "Common/Common_Macros.h"
#include "CortexM3_Core_SysTick_Cfg.h"
/*-----------------------------------------------Includes End---------------------------------------------*/


/*-------------------------------------------Macros Declaration Start-------------------------------------*/

/* Memory Mapping */
#define SysTick_BASE 							(0xE000E010UL)
#define SysTick 								((SysTick_RegTypeDef *)SysTick_BASE)

/* SysTick Control / Statues Register Definition */
#define SysTick_CSR_ENABLE_Pos					(0U)
#define SysTick_CSR_ENABLE_Msk					(1UL << (SysTick_CSR_ENABLE_Pos))

#define SysTick_CSR_TickINT_Pos					(1U)
#define SysTick_CSR_TickINT_Msk					(1UL << (SysTick_CSR_TickINT_Pos))

#define SysTick_CSR_CLKSOURCE_Pos				(2U)
#define SysTick_CSR_CLKSOURCE_Msk				(1UL << (SysTick_CSR_CLKSOURCE_Pos))

#define SysTick_CSR_COUNTFLAG_Pos				(16U)
#define SysTick_CSR_COUNTFLAG_Msk				(1 << (SysTick_CSR_COUNTFLAG_Pos))

/* SysTick Reload Register Definition */
#define SysTick_LOAD_RELOAD_Pos					(0U)
#define SysTick_LOAD_RELOAD_Msk					(0xFFFFFF << (SysTick_LOAD_RELOAD_Pos))

#define SysTick_SingleInterval_Mode					(0)
#define SysTick_PeriodicInterval_Mode				(1)
/*--------------------------------------------Macros Declaration End--------------------------------------*/




/*--------------------------------------Macros Functions Declaration Start--------------------------------*/

/*---------------------------------------Macros Functions Declaration End---------------------------------*/




/*-----------------------------------------Data Type Declaration Start------------------------------------*/
typedef struct{
	volatile uint32_t CTRL;								/*!< offset 0x000 (R/W) SysTick Control and Status Register */
	volatile uint32_t LOAD;								/*!< offset 0x004 (R/W) SysTick Reload Value Register */
	volatile uint32_t VAL;								/*!< offset 0x008 (R/W) SysTick Current Value Register */
	volatile uint32_t CALIB;							/*!< offset 0x00C (R/ ) SysTick Calibration Value Register */
}SysTick_RegTypeDef;

typedef void(* ptrFunction) (void);
/*------------------------------------------Data Type Declaration End-------------------------------------*/


/*-------------------------------------Software Interfaces Declaration Start------------------------------*/

/*\brief System Tick Configuration
 * \details
 *\param [in]	SysTick (Number of Ticks between two interrupts)
 *\return	Check Value
 */
uint8_t SysTick_Init(uint32_t SyTick_Ticks);


/*\brief System Tick DeInitialaization
 * \details
 *\param [in] -> None
 *\return -> None
 */
void SysTick_DeInt(void);

/*\brief System will wait till reach the flag
 * \details	Delay function in microsecond
 *\param [in] -> SysTick_Ticks (Number of Ticks between two interrupts)
 *\return -> None
 */
void SysTick_WaitBlocking(uint32_t SysTick_Ticks);



/*\brief System Tick trigger a callback one time once calculate the need ticks
 * \details	Non-Blocking call, trigger a callback once calculate the needed ticks
 *\param [in] SysTick_Ticks (Number of Ticks between two interrupts)
 *\param [in] Callback address of the callback function
 *\return -> none
 */
void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction * CallBack);


/*\brief System Tick trigger a callback periodically once calculate the need ticks
 * \details	Non-Blocking call, trigger a callback once calculate the needed ticks
 *\param [in]	SysTick_Ticks (Number of Ticks between two interrupts)
 *\param [in]	Callback address of the callback function
 *\return -> none
 */
void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction * CallBack);



/*\brief Get Remaining System Ticks
 *\details	Get Remaining System Ticks
 *\param [in] -> None
 *\return -> Remaining System Ticks
 */
uint32_t SysTick_GetRemainingTicks(void);


/*\brief Get Elapsed System Ticks
 *\details	Get Elapsed System Ticks
 *\param [in] -> None
 *\return -> Elapsed System Ticks
 */
uint32_t SysTick_GetElapsedTicks(void);



/*--------------------------------------Software Interfaces Declaration End-------------------------------*/


#endif /* CORTEXM3_CORTEXM3_CORE_SYSTICK_H_ */
