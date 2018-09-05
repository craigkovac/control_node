/**
  ******************************************************************************
  * @file    main.c
  * @author  Prem
  * @version V1.0.0
  * @date    16-August-2017
  * @brief   Sensor Node Main
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0xx_hal_adc.h"


/* peripheral files ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static 				TIM_HandleTypeDef      	s_TimerInstance2;
static volatile 	uint8_t  				timer_flag;
static 				uint32_t 				count = 0;
static 				ADC_HandleTypeDef 		g_AdcHandle;
static 				uint32_t				g_ADCValue;
static 				uint32_t				g_MeasurementNumber;

/* Private function prototypes -----------------------------------------------*/

static void peri_clk_int(void);
static void timer_init(void);
static void hw_init(void);
static void init_gpio(void);
static void adc_channel_init(void);
static void run_fast_function(void);
static void ms_loop(void);


int main(void)	//task scheduler
{
	hw_init();

	//initilize interrupts
	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);


    HAL_ADC_Start(&g_AdcHandle);
	for(;;)
	{

		if (HAL_ADC_PollForConversion(&g_AdcHandle, 1000000) == HAL_OK)
		{
			g_ADCValue = HAL_ADC_GetValue(&g_AdcHandle);
			g_MeasurementNumber++;// just a number to count number of measuerments taken so far
		}
		run_fast_function();
		if (timer_flag == 1)
		{
			timer_flag = 0;
			ms_loop();
		}
	}
}


void run_fast_function(void)
{
	//do the analog conversion here
}

void run_1ms_function(void)
{
	//every 20-30 ms send one can packet
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
}

static void timer_init(void)
{
	s_TimerInstance2.Instance = TIM2;
	s_TimerInstance2.Init.Prescaler = 40000;
	s_TimerInstance2.Init.CounterMode = TIM_COUNTERMODE_UP;
	s_TimerInstance2.Init.Period = 500;
	s_TimerInstance2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	s_TimerInstance2.Init.RepetitionCounter = 0;
	//s_TimerInstance2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

	HAL_TIM_Base_Init(&s_TimerInstance2);

    HAL_TIM_Base_Start_IT(&s_TimerInstance2);


}

static void init_gpio(void)
{

	GPIO_InitTypeDef gpio;
	gpio.Pin = GPIO_PIN_3;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &gpio);	// what does this pin do?

	gpio.Pin = GPIO_PIN_0;			// what does this pin do?
	HAL_GPIO_Init(GPIOC, &gpio);

	gpio.Pin  = GPIO_PIN_1;
	gpio.Mode = GPIO_MODE_ANALOG;
	gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &gpio);

}

static void ms_loop(void)
{
    static uint8_t count;
    //1 ms stuff();
    switch (count)
    {
        case 0:
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0);
        break;
        case 1:
            //10 ms other()
        break;
    }
    if (count < 9)
    {
        count++;
    }
    else
    {
        count = 0;
    }
}

static void peri_clk_int(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__TIM2_CLK_ENABLE(); 			//same as __HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();


}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance==TIM2) //check if the interrupt comes from TIM2
        {
        	count++;
        }
}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	timer_flag = 1;
//}

static void hw_init(void)
{

	peri_clk_int();
	init_gpio();
	timer_init();
	adc_channel_init();


}


static void adc_channel_init(void)
{
	ADC_ChannelConfTypeDef adcChannel;

    g_AdcHandle.Instance = ADC1;
    g_AdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
    g_AdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
    g_AdcHandle.Init.ScanConvMode = DISABLE;
    g_AdcHandle.Init.ContinuousConvMode = ENABLE;
    g_AdcHandle.Init.DiscontinuousConvMode = DISABLE;
    //g_AdcHandle.Init.NbrOfDiscConversion = 0;
    g_AdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    //g_AdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
    g_AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    //g_AdcHandle.Init.NbrOfConversion = 1;
    g_AdcHandle.Init.DMAContinuousRequests = ENABLE;
    g_AdcHandle.Init.EOCSelection = DISABLE;

    adcChannel.Channel = ADC_CHANNEL_0;
    adcChannel.Rank = 1;
    adcChannel.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
    HAL_ADC_Init(&g_AdcHandle);
    HAL_ADC_ConfigChannel(&g_AdcHandle, &adcChannel);
}
