/**
 ******************************************************************************
 * @file           : STM32F1xx_Peripherals_Defs.h
 * @author         : Ahmed Naeim
 * @brief          : Contains Data Structures and Address Mapping for all peripherals
 ******************************************************************************
**/


#ifndef HAL_DRIVERS_COMMON_STM32F1XX_PERIPHERALS_DEFS_H_
#define HAL_DRIVERS_COMMON_STM32F1XX_PERIPHERALS_DEFS_H_

/*----------------------------------------------Includes Start--------------------------------------------*/
#include "Common/STD_Types.h"
/*-----------------------------------------------Includes End---------------------------------------------*/


/*-------------------------------------------Macros Declaration Start-------------------------------------*/
/*!< Peripheral Memory Map */
#define PERIPH_BASE							0x40000000UL										/* Peripheral Base Address in the alias region */
#define AHBPERIPH_BASE						(PERIPH_BASE + 0x00018000UL)						/* AHB Peripheral Base Address in the alias region */
#define RCC_BASE							(AHBPERIPH_BASE + 0x00009000UL)						/* RCC Peripheral Base Address in alias region */
#define RCC									((RCC_TypeDef *) RCC_BASE)							/* Explecit casting to make a pointer of the struct (RCC_TypeDef starting from RCC_BASE */


										/* Bit Definition for RCC APB2ENR */
#define RCC_APB2ENR_GPIOAEN_Pos					(2U)
#define RCC_APB2ENR_GPIOAEN_Msk					(0x1UL << RCC_APB2ENR_GPIOAEN_Pos)				/* 0x00000004 */

#define RCC_APB2ENR_GPIOBEN_Pos					(3U)
#define RCC_APB2ENR_GPIOBEN_Msk					(0x1UL << RCC_APB2ENR_GPIOBEN_Pos)				/* 0x00000008 */

#define RCC_APB2ENR_GPIOCEN_Pos					(4U)
#define RCC_APB2ENR_GPIOCEN_Msk					(0x1UL << RCC_APB2ENR_GPIOCEN_Pos)				/* 0x00000010 */

#define RCC_APB2ENR_GPIODEN_Pos					(5U)
#define RCC_APB2ENR_GPIODEN_Msk					(0x1UL << RCC_APB2ENR_GPIODEN_Pos)				/* 0x00000020 */

#define RCC_APB2ENR_GPIOEEN_Pos					(6U)
#define RCC_APB2ENR_GPIOEEN_Msk					(0x1UL << RCC_APB2ENR_GPIOEEN_Pos)				/* 0x00000040 */

#define RCC_APB2ENR_GPIOFEN_Pos					(7U)
#define RCC_APB2ENR_GPIOFEN_Msk					(0x1UL << RCC_APB2ENR_GPIOFEN_Pos)				/* 0x00000080 */

#define RCC_APB2ENR_GPIOGEN_Pos					(8U)
#define RCC_APB2ENR_GPIOGEN_Msk					(0x1UL << RCC_APB2ENR_GPIOGEN_Pos)				/* 0x00000100 */


									/* Bit Definition for RCC_CR bits */
#define RCC_CR_HSEON_Pos						(16U)
#define RCC_CR_HSEON_Msk						(0x1UL << RCC_CR_HSEON_Pos)						/* 0x00000000 */




/* @defgroup RCC Oscillator_Type Oscillator Type */
#define RCC_OSCILLATORTYPE_NONE					0x00000000U
#define RCC_OSCILLATORTYPE_HSE					0x00000001U
#define RCC_OSCILLATORTYPE_HSI					0x00000002U
#define RCC_OSCILLATORTYPE_LSE					0x00000004U
#define RCC_OSCILLATORTYPE_LSI					0x00000008U

/* @defgroup RCC_HSE_Config HSE Config */
#define RCC_HSE_OFF								((uint8_t) 0x00)
#define RCC_HSE_ON								((uint8_t) 0x01)

/* @defgroup RCC_HSE_Config LSE Config */
#define RCC_LSE_OFF								((uint8_t) 0x00)
#define RCC_LSE_ON								((uint8_t) 0x01)

/* @defgroup RCC_HSE_Config HSI Config */
#define RCC_HSI_OFF								((uint8_t) 0x00)
#define RCC_HSI_ON								((uint8_t) 0x01)

/* @defgroup RCC_HSE_Config LSI Config */
#define RCC_LSI_OFF								((uint8_t) 0x00)
#define RCC_LSI_ON								((uint8_t) 0x01)


										/*--------------------  Bit Definition for RCC_CFGR bits --------------------*/
#define RCC_CFGR_SW0_Pos						(0U)
#define RCC_CFGR_SW0_Msk						(0x1UL << RCC_CFGR_SW0_Pos)					/* 0x00000081 */

#define RCC_CFGR_SW1_Pos						(1U)
#define RCC_CFGR_SW1_Msk						(0x1UL << RCC_CFGR_SW1_Pos)					/* 0x00000010 */



										/*-------------------- RCC_AHB_Clock_Source --------------------*/
/* @defgroup RCC_AHB_Clock_Source configuration*/
#define RCC_CFGR_HPRE_Pos						(4U)											/*!< the start of HPRE bits is 4*/
#define RCC_CFGR_HPRE_Msk						(0xFUL << RCC_CFGR_HPRE_Pos)					/*!< Mask all 4 bits with 1111 (0xF) starting from the 4th bit (Pos)*/

/* @defgroup AHB prescaler RCC_AHB_Clock_Source */
#define RCC_CFGR_HPRE_DIV1						0x00000000UL									/*!< SYSCLK not divided*/
#define RCC_CFGR_HPRE_DIV2						0x00000080UL									/*!< SYSCLK divided by 2*/
#define RCC_CFGR_HPRE_DIV4						0x00000090UL									/*!< SYSCLK divided by 4*/
#define RCC_CFGR_HPRE_DIV8						0x000000A0UL									/*!< SYSCLK divided by 8*/
#define RCC_CFGR_HPRE_DIV16						0x000000B0UL									/*!< SYSCLK divided by 16*/
#define RCC_CFGR_HPRE_DIV64						0x000000C0UL									/*!< SYSCLK divided by 64*/
#define RCC_CFGR_HPRE_DIV128					0x000000D0UL									/*!< SYSCLK divided by 128*/
#define RCC_CFGR_HPRE_DIV256					0x000000E0UL									/*!< SYSCLK divided by 256*/
#define RCC_CFGR_HPRE_DIV512					0x000000F0UL									/*!< SYSCLK divided by 512*/


										/*-------------------- RCC_APB1_Clock_Source --------------------*/
/* @defgroup RCC_APB1_Clock_Source configuration*/
#define RCC_CFGR_PPRE1_Pos						(11U)											/*!< the start of HPRE bits is 11*/
#define RCC_CFGR_PPRE1_Msk						(0x7UL << RCC_CFGR_PPRE1_Pos)					/*!< Mask all 3 bits with 111 (0x7) starting from the 11th bit (Pos)*/

/* @defgroup APB1 low-speed PCLK1 prescaler RCC_APB1_Clock_Source */
#define RCC_CFGR_PPRE1_DIV1						0x00000000UL									/*!< HCLK not divided*/
#define RCC_CFGR_PPRE1_DIV2						0x00000400UL									/*!< HCLK divided by 2*/
#define RCC_CFGR_PPRE1_DIV4						0x00000500UL									/*!< HCLK divided by 4*/
#define RCC_CFGR_PPRE1_DIV8						0x00000600UL									/*!< HCLK divided by 8*/
#define RCC_CFGR_PPRE1_DIV16					0x00000700UL									/*!< HCLK divided by 16*/

										/*-------------------- RCC_APB2_Clock_Source --------------------*/
/* @defgroup RCC_APB2_Clock_Source configuration*/
#define RCC_CFGR_PPRE2_Pos						(8U)											/*!< the start of HPRE bits is 8*/
#define RCC_CFGR_PPRE2_Msk						(0x7UL << RCC_CFGR_PPRE2_Pos)					/*!< Mask all 3 bits with 111 (0x7) starting from the 8th bit (Pos)*/

/* @defgroup APB2 high-speed PCLK2 prescaler RCC_APB2_Clock_Source */
#define RCC_CFGR_PPRE2_DIV1						0x00000000UL									/*!< HCLK not divided*/
#define RCC_CFGR_PPRE2_DIV2						0x00002000UL									/*!< HCLK divided by 2*/
#define RCC_CFGR_PPRE2_DIV4						0x00002800UL									/*!< HCLK divided by 4*/
#define RCC_CFGR_PPRE2_DIV8						0x00003000UL									/*!< HCLK divided by 8*/
#define RCC_CFGR_PPRE2_DIV16					0x00003800UL									/*!< HCLK divided by 16*/



/*--------------------------------------------Macros Declaration End--------------------------------------*/



/*--------------------------------------Macros Functions Declaration Start--------------------------------*/

/*---------------------------------------Macros Functions Declaration End---------------------------------*/



/*-----------------------------------------Data Type Declaration Start------------------------------------*/

/*
 * @brief RCC Registers structure Definition
 */
typedef struct{
	volatile uint32_t CR;					/*!<  RCC Clock Control register									Address Offset 0x00 */
	volatile uint32_t CFGR;					/*!<  RCC Clock Configuration register								Address Offset 0x04 */
	volatile uint32_t CIR;					/*!<  RCC Clock Interrupt register									Address Offset 0x08 */
	volatile uint32_t APB2RSTR;				/*!<  RCC APB2 Peripheral Reset register							Address Offset 0x0C */
	volatile uint32_t APB1RSTR;				/*!<  RCC APB1 Peripheral Reset register							Address Offset 0x010 */
	volatile uint32_t AHBENR;				/*!<  RCC AHB CLock register										Address Offset 0x14 */
	volatile uint32_t APB2ENR;				/*!<  RCC APB2 Peripheral Clock Enable register						Address Offset 0x18 */
	volatile uint32_t APB1ENR;				/*!<  RCC APB1 Peripheral Clock Enable register						Address Offset 0x1C */
	volatile uint32_t BDCR;					/*!<  RCC Backup domain control register							Address Offset 0x20 */
	volatile uint32_t CSR;					/*!<  RCC clock control & Statues Register register					Address Offset 0x24 */

}RCC_TypeDef;


/*------------------------------------------Data Type Declaration End-------------------------------------*/



/*-------------------------------------Software Interfaces Declaration Start------------------------------*/

/*--------------------------------------Software Interfaces Declaration End-------------------------------*/


#endif /* HAL_DRIVERS_COMMON_STM32F1XX_PERIPHERALS_DEFS_H_ */
