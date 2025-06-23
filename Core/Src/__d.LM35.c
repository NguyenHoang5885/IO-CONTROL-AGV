#include <__b.Var_global.h>
#include "__d.LM35.h"
#include "main.h"

uint16_t AD;
extern float Voltage, TEMP;

extern ADC_HandleTypeDef hadc1;

float GET_TEMP_POWER(void){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	AD = HAL_ADC_GetValue(&hadc1);
	Voltage = ((float)AD*3.3)/4095;
	return TEMP = Voltage*100;
}

