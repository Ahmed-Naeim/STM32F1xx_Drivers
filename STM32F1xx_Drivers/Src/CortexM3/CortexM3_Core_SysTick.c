/**
 ******************************************************************************
 * @file           : CortexM3_Core_SysTick.c
 * @author         : Ahmed Naeim
 * @brief          : Contains static code to control SysTick Timer
 ******************************************************************************
**/

#include "CortexM3/CortexM3_Core_SysTick.h"


static volatile ptrFunction SysTick_CallBack = NULL;
static volatile uint8_t SysTick_Mode = SysTick_SingleInterval_Mode;

/*\brief System Tick Configuration
 * \details
 *\param [in]	SysTick (Number of Ticks between two interrupts)
 *\return	Check Value
 */
uint8_t SysTick_Init(uint32_t SysTick_Ticks)
{
	uint8_t RetVal =0;

	if(SysTick_Ticks > SysTick_LOAD_RELOAD_Msk)
	{
		RetVal=1;
	}
	else
	{
		/*Disable SysTick Counter*/
		CLEAR_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);

		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;

		/*Reset SysTick counter value*/
		SysTick->VAL = 0;

		/*select processor clock*/
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV1)
		SET_BIT(SysTick->CTRL,SysTick_CSR_CLKSOURCE_Msk);

#elif (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV8)
		CLEAR_BIT(SysTick->CTRL,SysTick_CSR_CLKSOURCE_Msk);

#else
#error "Invalid Clock Source"
#endif

		/*Disable SysTick_IRQ*/
		CLEAR_BIT(SysTick->CTRL,SysTick_CSR_TickINT_Msk);
	}
	return RetVal;

}


/*\brief System Tick DeInitialaization
 * \details
 *\param [in] -> None
 *\return -> None
 */
void SysTick_DeInt(void)
{
	/*Disable SysTick Counter*/
	CLEAR_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);

	/*Reset Reload Register*/
	SysTick->LOAD = 0;

	/*Reset SysTick counter value*/
	SysTick->VAL = 0;

	/*Disable SysTick_IRQ*/
	CLEAR_BIT(SysTick->CTRL,SysTick_CSR_TickINT_Msk);

}


/*\brief System will wait till reach the flag
 * \details Delay function in microsecond
 *\param [in] -> SysTick_Ticks (Number of Ticks between two interrupts)
 *\return -> None
 */
void SysTick_WaitBlocking(uint32_t SysTick_Ticks)
{
	/*Set Reload Register to SysTick_Ticks*/
	SysTick->LOAD = SysTick_Ticks;

	/*Enable SysTick Counter*/
	SET_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);

	/*Wait for COUNTFLAG returns 1*/
	while(READ_BIT(SysTick->CTRL, SysTick_CSR_COUNTFLAG_Msk) == 0);

	/*Disable SysTick Counter*/
	CLEAR_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);

	/*Reset Reload Register*/
	SysTick->LOAD = 0;

	/*Reset SysTick counter value*/
	SysTick->VAL = 0;


}


/*\brief System Tick trigger a callback one time once calculate the need ticks
 * \details	Non-Blocking call, trigger a callback once calculate the needed ticks
 *\param [in] SysTick_Ticks (Number of Ticks between two interrupts)
 *\param [in] Callback address of the callback function
 *\return -> none
 */
void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction * CallBack)
{
	if(CallBack != NULL)
	{
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;

		/*Copy the user callback to a local ptr function*/
		SysTick_CallBack = CallBack;

		/*Set SysTick Timer to Single Interval Mode*/
		SysTick_Mode = SysTick_SingleInterval_Mode;
		/*Enable SysTick_IRQ NVIC Line*/
		SET_BIT(SysTick->CTRL,SysTick_CSR_TickINT_Msk);

		/*Set SysTick Timer IRQ Priority Least Urgent : Highest priority number*/

		/*Enable SysTick Timer to asserts the SysTick exception request*/
		SET_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);


	}
	else
	{
		/*Nothing*/
	}

}


/*\brief System Tick trigger a callback periodically once calculate the need ticks
 * \details	Non-Blocking call, trigger a callback once calculate the needed ticks
 *\param [in]	SysTick_Ticks (Number of Ticks between two interrupts)
 *\param [in]	Callback address of the callback function
 *\return -> none
 */
void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction * CallBack)
{
	if(CallBack != NULL)
	{
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;

		/*Copy the user callback to a local ptr function*/
		SysTick_CallBack = CallBack;

		/*Set SysTick Timer to Periodic Interval Mode*/
		SysTick_Mode = SysTick_PeriodicInterval_Mode;

		/*Enable SysTick_IRQ NVIC Line*/
		SET_BIT(SysTick->CTRL,SysTick_CSR_TickINT_Msk);

		/*Set SysTick Timer IRQ Priority Least Urgent : Highest priority number*/

		/*Enable SysTick Timer to asserts the SysTick exception request*/
		SET_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);


	}
	else
	{
		/*Nothing*/
	}

}

/*\brief Get Remaining System Ticks
 *\details	Get Remaining System Ticks
 *\param [in] -> None
 *\return -> Remaining System Ticks
 */
uint32_t SysTick_GetRemainingTicks(void)
{
	uint32_t RemainingTicks =0;
	/*Copy SysTick Counter Register to a local variable*/
	RemainingTicks = SysTick->VAL;
	/*Return the Local Variable*/
	return RemainingTicks;
}


/*\brief Get Elapsed System Ticks
 *\details	Get Elapsed System Ticks
 *\param [in] -> None
 *\return -> Elapsed System Ticks
 */
uint32_t SysTick_GetElapsedTicks(void)
{
	uint32_t ElapsedTicks =0;
	/*Copy SysTick Counter Register to a local variable*/
	ElapsedTicks = (SysTick-> LOAD) - (SysTick->VAL);
	/*Return the Local Variable*/
	return ElapsedTicks;
}

void SysTick_Handler (void)
{
	if(SysTick_Mode == SysTick_SingleInterval_Mode)
	{
		/*Disable SysTick Counter*/
		CLEAR_BIT(SysTick->CTRL,SysTick_CSR_ENABLE_Msk);

		/*Reset Reload Register*/
		SysTick->LOAD = 0;

		/*Reset SysTick counter value*/
		SysTick->VAL = 0;

		/*Disable SysTick_IRQ*/
		CLEAR_BIT(SysTick->CTRL,SysTick_CSR_TickINT_Msk);
	}
	else
	{
		/*Nothing*/
	}

	if (SysTick_CallBack){
		SysTick_CallBack();
	}
}
