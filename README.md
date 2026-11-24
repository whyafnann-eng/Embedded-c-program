# Embedded-c-program
Embedded C Programming – AVR Microcontroller Programs
#include "main.h"

#define MOTOR (1U << 1)

uint32_t adc_value;
float temperature;

ADC_HandleTypeDef hadc1;

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();

    while (1)
    {
        HAL_ADC_Start(&hadc1);

        HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

        adc_value = HAL_ADC_GetValue(&hadc1);

        temperature = (adc_value * 3.3 * 100.0) / 4095.0;

        if (temperature > 40.0)
        {
            GPIOA->ODR |= MOTOR;     // Motor ON
        }
        else
        {
            GPIOA->ODR &= ~MOTOR;    // Motor OFF
        }

        HAL_Delay(500);
    }
}
