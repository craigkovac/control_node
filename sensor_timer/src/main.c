#include "stm32f0xx.h"
#include "stm32f0xx_hal_gpio.h"
#include "stm32f0xx_hal_rcc.h"
#include "stm32f0xx_hal_tim.h"
#include "core_cm0.h"
#include "stm32f042x6.h"


static uint8_t counter = 0;
static TIM_HandleTypeDef timer;
RCC_ClkInitTypeDef rcc;
static void init_timer(void);
//static volatile uint8_t timer_flag = 0;


int main(void)
{






	/*
	rcc.ClockType =
	HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);
	*/
	init_timer();
	while(1)
	{
		counter++;
	}

	return 0;
}


//HAL_RCC_ClockConfig

void init_timer(void)
{

	__HAL_RCC_TIM2_CLK_ENABLE();
	timer.Instance = TIM2;
	timer.Init.Prescaler = 48000;
	timer.Init.CounterMode = TIM_COUNTERMODE_DOWN;
	timer.Init.Period = 50000;
	timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer.Init.RepetitionCounter = 1;


	HAL_TIM_Base_Init(&timer);
	__HAL_TIM_CLEAR_FLAG(&timer, TIM_FLAG_UPDATE);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_TIM_Base_Start(&timer);
	//HAL_TIM_Base_Start_IT(&timer);
	if (HAL_TIM_Base_Start_IT(&timer) != HAL_OK) {
	       counter++;
	}
	counter++;

}




void TIM2_IRQHandler(void)
{
	//timer_flag = 1;
	HAL_TIM_IRQHandler(&timer);

}


