/*
 * STM32F1xx_HAL_RCC.c
 *
 *  Created on: Dec 3, 2023
 *      Author: iT
 */
#include "HAL_Drivers/RCC/STM32F1xx_HAL_RCC.h"

/*
 * @brief-> turns on the needed oscillator selected by the user
 * parameters-> address for the new object from RCC_OscInitTypeDef structure
 * Output-> Statues check variable (Ok/Error)
 * */
HAL_StatuesTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef* RCC_OscInitStruct)
{
	HAL_StatuesTypeDef RetStatues = HAL_OK;

	if(NULL == RCC_OscInitStruct)
	{
		RetStatues = HAL_ERROR;
	}
	else
	{
												/* --------------------HSE Configuration-------------------- */
		if(RCC_OSCILLATORTYPE_HSE == RCC_OscInitStruct -> Oscillator_Type)
		{
			if(RCC_HSE_ON == RCC_OscInitStruct->HSEState)
			{
				/* HSE selected as system clock */
				CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW0_Msk);
				SET_BIT(RCC->CFGR, RCC_CFGR_SW1_Msk);
				/* HSE Oscillator ON */
				SET_BIT(RCC->CR, RCC_CR_HSEON_Msk);
			}
			else
			{
				CLEAR_BIT(RCC->CR, RCC_CR_HSEON_Msk);

			}

		}
		else if(RCC_OSCILLATORTYPE_LSE == RCC_OscInitStruct -> Oscillator_Type)
		{
			/* TBD */
		}
		else if(RCC_OSCILLATORTYPE_HSI == RCC_OscInitStruct -> Oscillator_Type)
		{
			/* TBD */
		}
		else if(RCC_OSCILLATORTYPE_LSI == RCC_OscInitStruct -> Oscillator_Type)
		{
			/* TBD */
		}
		else
		{
			/* Nothing */
		}
	}

	return RetStatues;
}


/*
 * @brief-> selection for the needed prescaler for all available clock dividers
 * parameters-> address for the new object from RCC_CLKInitTypeDef structure
 * Output-> Statues check variable (Ok/Error)
 * */
HAL_StatuesTypeDef HAL_RCC_ClockConjfig(RCC_CLKInitTypeDef* RCC_CLKInitStruct)
{
	HAL_StatuesTypeDef RetStatues = HAL_OK;

	if (NULL== RCC_CLKInitStruct)
	{
		RetStatues= HAL_ERROR;
	}
	else
	{
		MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE_Msk, RCC_CLKInitStruct-> AHBCLKDivider);
		MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1_Msk, RCC_CLKInitStruct-> APB1CLKDivider);
		MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2_Msk, RCC_CLKInitStruct-> APB2CLKDivider);

	}

	return RetStatues;
}
