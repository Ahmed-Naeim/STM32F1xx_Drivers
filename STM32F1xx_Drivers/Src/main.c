/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Naeim
 * @brief          : Main program body
 ******************************************************************************
**/


#include "CortexM3/CortexM3_Interface.h"
#include "HAL_Drivers/RCC/STM32F1xx_HAL_RCC.h"

uint8_t RetVal = 0;
uint32_t MainAppCounter =0;

/*
static volatile uint8_t USART3_IRQnHandler_Flag=0;
static volatile uint8_t EXTI15_10_IRQnHandler_Flag=0;
static volatile uint8_t RTCAlarm_IRQnHandler_Flag=0;

static volatile uint8_t USART3_IRQnHandler_Active_Flag1=0;
static volatile uint8_t USART3_IRQnHandler_Active_Flag2=0;
static uint32_t PriorityGroupingValue=0;
*/

void SysTick_Func1(void){
	MainAppCounter++;
}

void System_Clock_Config(void);

int main(void)
{
	/*
	NVIC_EnableIRQ(USART3_IRQn);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_EnableIRQ(RTCAlarm_IRQn);

	NVIC_SetPendingIRQ(USART3_IRQn);
	NVIC_SetPendingIRQ(EXTI15_10_IRQn);
	NVIC_SetPendingIRQ(RTCAlarm_IRQn);
	*/
	/*	SCB_SetPriorityGrouping(SCB_PRIORITYGROUP_2);
		PriorityGroupingValue= SCB_GetPriorityGrouping();
	*/


	HAL_RCC_GPIOC_CLK_ENABLE();
	HAL_RCC_GPIOC_CLK_DISABLE();
	HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_RCC_GPIOA_CLK_DISABLE();

	RetVal = SysTick_Init(1000);

	SysTick_WaitBlocking(1000);

	System_Clock_Config();
    /* Loop forever */
	while(1)
	{
		SysTick_PeriodicInterval(1000, SysTick_Func1);
		/*USART3_IRQnHandler_Active_Flag1= NVIC_GetActive(USART3_IRQn);*/

	}
}
/*
void USART3_IRQnHandler(void)
{
	USART3_IRQnHandler_Flag=1;
	USART3_IRQnHandler_Active_Flag2= NVIC_GetActive(USART3_IRQn);
}

void EXTI15_10_IRQnHandler(void)
{
	EXTI15_10_IRQnHandler_Flag=1;
}

void RTCAlarm_IRQnHandler(void)
{
	RTCAlarm_IRQnHandler_Flag=1;
}
*/

void System_Clock_Config(void)
{
	HAL_StatuesTypeDef RetStatues = HAL_OK;

	RCC_OscInitTypeDef RCC_OscInitStruct= {0};
	RCC_CLKInitTypeDef RCC_CLKInitStruct={0};

	RCC_OscInitStruct. Oscillator_Type= RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct. HSEState= RCC_HSE_ON;
	RetStatues = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	if(RetStatues == HAL_ERROR)
	{

	}
	else
	{
		/* Nothing */
	}

	RCC_CLKInitStruct.AHBCLKDivider = RCC_SYSCLK_AHB_DIV1;
	RCC_CLKInitStruct.APB1CLKDivider = RCC_HCLK_APB1_DIV1;
	RCC_CLKInitStruct.APB2CLKDivider = RCC_HCLK_APB2_DIV1;

	RetStatues = HAL_RCC_ClockConjfig(&RCC_CLKInitStruct);
	if(RetStatues == HAL_ERROR)
	{

	}
	else
	{
		/* Nothing */
	}
}
