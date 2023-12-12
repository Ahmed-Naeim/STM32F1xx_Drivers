/**
 ******************************************************************************
 * @file           : STM32F1xx_HAL_RCC.h
 * @author         : Ahmed Naeim
 * @brief          : Contains declaration for RCC
 ******************************************************************************
**/


#ifndef HAL_DRIVERS_RCC_STM32F1XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F1XX_HAL_RCC_H_


/*----------------------------------------------Includes Start--------------------------------------------*/
#include "Common/Common_Macros.h"
#include "HAL_Drivers/Common/STM32F1xx_HAL_Def.h"
#include"HAL_Drivers/Common/STM32F1xx_Peripherals_Defs.h"
/*-----------------------------------------------Includes End---------------------------------------------*/

/*-------------------------------------------Macros Declaration Start-------------------------------------*/


/* @defgroup AHB Prescaler for user */
#define RCC_SYSCLK_AHB_DIV1						RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_AHB_DIV2						RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_AHB_DIV4						RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_AHB_DIV8						RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_AHB_DIV16					RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_AHB_DIV64					RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_AHB_DIV128					RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_AHB_DIV256					RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_AHB_DIV512					RCC_CFGR_HPRE_DIV512


/* @defgroup APB2 Prescaler for user */
#define RCC_HCLK_APB2_DIV1						RCC_CFGR_PPRE2_DIV1
#define RCC_HCLK_APB2_DIV2						RCC_CFGR_PPRE2_DIV2
#define RCC_HCLK_APB2_DIV4						RCC_CFGR_PPRE2_DIV4
#define RCC_HCLK_APB2_DIV8						RCC_CFGR_PPRE2_DIV8
#define RCC_HCLK_APB2_DIV16						RCC_CFGR_PPRE2_DIV16


/* @defgroup APB1 Prescaler for user */
#define RCC_HCLK_APB1_DIV1						RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_APB1_DIV2						RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_APB1_DIV4						RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_APB1_DIV8						RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_APB1_DIV16						RCC_CFGR_PPRE1_DIV16


/*--------------------------------------------Macros Declaration End--------------------------------------*/



/*--------------------------------------Macros Functions Declaration Start--------------------------------*/

												/* GPIO Enable */
#define HAL_RCC_GPIOA_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOAEN_Msk)) 					/* GPIOA Clock Enable (r/w) */
#define HAL_RCC_GPIOB_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOBEN_Msk))					/* GPIOB Clock Enable (r/w) */
#define HAL_RCC_GPIOC_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOCEN_Msk))					/* GPIOC Clock Enable (r/w) */
#define HAL_RCC_GPIOD_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIODEN_Msk))					/* GPIOD Clock Enable (r/w) */
#define HAL_RCC_GPIOE_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOEEN_Msk))					/* GPIOE Clock Enable (r/w) */
#define HAL_RCC_GPIOF_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOFEN_Msk))					/* GPIOF Clock Enable (r/w) */
#define HAL_RCC_GPIOG_CLK_ENABLE()			(SET_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOGEN_Msk))					/* GPIOG Clock Enable (r/w) */

												/* GPIO Disable */
#define HAL_RCC_GPIOA_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOAEN_Msk))					/* GPIOA Clock Disable (r/w) */
#define HAL_RCC_GPIOB_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOBEN_Msk))					/* GPIOB Clock Disable (r/w) */
#define HAL_RCC_GPIOC_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOCEN_Msk))					/* GPIOC Clock Disable (r/w) */
#define HAL_RCC_GPIOD_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIODEN_Msk))					/* GPIOD Clock Disable (r/w) */
#define HAL_RCC_GPIOE_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOEEN_Msk))					/* GPIOE Clock Disable (r/w) */
#define HAL_RCC_GPIOF_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOFEN_Msk))					/* GPIOF Clock Disable (r/w) */
#define HAL_RCC_GPIOG_CLK_DISABLE()			(CLEAR_BIT(RCC-> APB2ENR, RCC_APB2ENR_GPIOGEN_Msk))					/* GPIOG Clock Disable (r/w) */


/*---------------------------------------Macros Functions Declaration End---------------------------------*/



/*-----------------------------------------Data Type Declaration Start------------------------------------*/


/*
 * @brief RCC Internal/External Oscillator (HSE, HSI, LSE, and LSI configuration structure Definition
 */
typedef struct{
	uint32_t Oscillator_Type;				/*!< THIS OSCILLATOR CAN BE CONFIGURED
	 	 	 	 	 	 	 	 	 	 	 	 This Parameter can be a value of @ref RCC Oscilator_Type*/
	uint32_t HSEState;						/* !< The new state of HSE
	 	 	 	 	 	 	 	 	 	 	 	 This Parameter can be a value of @ref RCC_HSE_Config*/
	uint32_t LSEState;						/* !< The new state of HSE
	 	 	 	 	 	 	 	 	 	 	 	 This Parameter can be a value of @ref RCC_LSE_Config*/
	uint32_t HSIState;						/* !< The new state of HSE
	 	 	 	 	 	 	 	 	 	 	 	 This Parameter can be a value of @ref RCC_HSI_Config*/
	uint32_t LSIState;						/* !< The new state of HSE
	 	 	 	 	 	 	 	 	 	 	 	 This Parameter can be a value of @ref RCC_LSI_Config*/


}RCC_OscInitTypeDef;

/*
 *@brief RCC Clock prescaler configuration structure definition
 * */
typedef struct
{
	uint32_t AHBCLKDivider;							/*!< The AHB Clock (HCLK) divider, This clock is derived from the system clock (SYSCLK)
	 	 	 	 	 	 	 	 	 	 	 	  	 	 This parameter can be a value of @ref RCC_AHB_Clock_Source*/
	uint32_t APB1CLKDivider;						/*!< The AHB Clock (PCLK1) divider, This clock is derived from the AHB clock (HCLK)
	 	 	 	 	 	 	 	 	 	 	 	  	 	 This parameter can be a value of @ref RCC_APB1_Clock_Source*/
	uint32_t APB2CLKDivider;						/*!< The AHB Clock (PCLK2) divider, This clock is derived from the AHB clock (HCLK)
	 	 	 	 	 	 	 	 	 	 	 	  	 	 This parameter can be a value of @ref RCC_APB2_Clock_Source*/


}RCC_CLKInitTypeDef;


/*------------------------------------------Data Type Declaration End-------------------------------------*/


/*-------------------------------------Software Interfaces Declaration Start------------------------------*/

/*
 * @brief-> turns on the needed oscillator selected by the user
 * parameters-> address for the new object from RCC_OscInitTypeDef structure
 * Output-> Statues check variable (Ok/Error)
 * */
HAL_StatuesTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef* RCC_OscInitStruct);



/*
 * @brief-> selection for the needed prescaler for all available clock dividers
 * parameters-> address for the new object from RCC_CLKInitTypeDef structure
 * Output-> Statues check variable (Ok/Error)
 * */
HAL_StatuesTypeDef HAL_RCC_ClockConjfig(RCC_CLKInitTypeDef* RCC_CLKInitStruct);

/*--------------------------------------Software Interfaces Declaration End-------------------------------*/


#endif /* HAL_DRIVERS_RCC_STM32F1XX_HAL_RCC_H_ */
