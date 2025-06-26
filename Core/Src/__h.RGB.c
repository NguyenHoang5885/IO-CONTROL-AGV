#include "__h.RGB.h"
#include <stdint.h>
#include "main.h"
extern TIM_HandleTypeDef htim3;
extern DMA_HandleTypeDef hdma_tim3_ch2;
#define Led_max 12

typedef struct{
	int num;
	uint8_t G;
	uint8_t R;
	uint8_t B;
}RGB;

RGB Led_Array[Led_max];
uint32_t Led_data[Led_max];
uint16_t PWM_data[(Led_max *24)+50];

void Init_RGB( int Green, int Red, int Blue){
	for(int i=0; i< Led_max; i++){
		Led_Array[i].num = i;
		Led_Array[i].G   = Green ;
		Led_Array[i].R   = Red   ;
		Led_Array[i].B   = Blue  ;
	}
	Convert_PWM();
}

void Set_Color_Led(int Number, int Green, int Red, int Blue){
	for(int i = 0; i < Led_max; i++){
		if(i == Number ){
			Led_Array[i].num = Number;
			Led_Array[i].G   = Green ;
			Led_Array[i].R   = Red   ;
			Led_Array[i].B   = Blue  ;
		}
	}
	Convert_PWM();
}

void Convert_PWM(){
	int count = 0;
	for(int i = 0; i < Led_max; i++){
		Led_data[i] = ((uint32_t)Led_Array[i].G << 16) | ((uint32_t)Led_Array[i].R << 8) | (uint32_t)Led_Array[i].B;

		for(int j=23; j>=0; j--){
			if(Led_data[i] & (1 << j) != 0){
				PWM_data[count] = 60;
			}
			else{
				PWM_data[count] = 30;
			}
			count++;
		}
	}

	for(int i=0; i=50; i++){
		PWM_data[count] = 0;
		count++;
	}
	HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_3, (uint32_t *)PWM_data, count);
}
