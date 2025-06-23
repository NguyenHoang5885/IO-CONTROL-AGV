#include <__c.IO_part.h>
#include "__b.Var_global.h"
#include "main.h"

extern uint8_t data_input[16];
extern uint8_t value ;
extern uint8_t gate  ;

typedef struct{
	const char* name;
	GPIO_TypeDef *port;
	uint16_t pin;
}GPIO;

GPIO GPIO_INPUT[16] = {
		{"MCU_IN0" , GPIOE, GPIO_PIN_2 },
		{"MCU_IN1" , GPIOE, GPIO_PIN_3 },
		{"MCU_IN2" , GPIOE, GPIO_PIN_4 },
		{"MCU_IN3" , GPIOE, GPIO_PIN_5 },
		{"MCU_IN4" , GPIOE, GPIO_PIN_6 },
		{"MCU_IN5" , GPIOC, GPIO_PIN_13},
		{"MCU_IN6" , GPIOC, GPIO_PIN_14},
		{"MCU_IN7" , GPIOC, GPIO_PIN_15},
		{"MCU_IN8" , GPIOF, GPIO_PIN_0 },
		{"MCU_IN9" , GPIOF, GPIO_PIN_1 },
		{"MCU_IN10", GPIOF, GPIO_PIN_2 },
		{"MCU_IN11", GPIOF, GPIO_PIN_3 },
		{"MCU_IN12", GPIOF, GPIO_PIN_4 },
		{"MCU_IN13", GPIOF, GPIO_PIN_5 },
		{"MCU_IN14", GPIOF, GPIO_PIN_6 },
		{"MCU_IN15", GPIOF, GPIO_PIN_7 }
};

GPIO GPIO_GND_OUTPUT[16]={
		{"GND_OUT_0" , GPIOB, GPIO_PIN_13},
		{"GND_OUT_1" , GPIOB, GPIO_PIN_15},
		{"GND_OUT_2" , GPIOD, GPIO_PIN_9 },
		{"GND_OUT_3" , GPIOD, GPIO_PIN_11},
		{"GND_OUT_4" , GPIOD, GPIO_PIN_13},
		{"GND_OUT_5" , GPIOD, GPIO_PIN_15},
		{"GND_OUT_6" , GPIOG, GPIO_PIN_3 },
		{"GND_OUT_7" , GPIOG, GPIO_PIN_5 },
		{"GND_OUT_8" , GPIOG, GPIO_PIN_7 },
		{"GND_OUT_9" , GPIOC, GPIO_PIN_10},
		{"GND_OUT_10", GPIOC, GPIO_PIN_12},
		{"GND_OUT_11", GPIOD, GPIO_PIN_1 },
		{"GND_OUT_12", GPIOD, GPIO_PIN_3 },
		{"GND_OUT_13", GPIOD, GPIO_PIN_5 },
		{"GND_OUT_14", GPIOD, GPIO_PIN_7 },
		{"GND_OUT_15", GPIOG, GPIO_PIN_10}
};

GPIO GPIO_VCC_OUTPUT[16]={
		{"VCC_OUT_0" , GPIOB, GPIO_PIN_12},
		{"VCC_OUT_1" , GPIOB, GPIO_PIN_14},
		{"VCC_OUT_2" , GPIOD, GPIO_PIN_8 },
		{"VCC_OUT_3" , GPIOD, GPIO_PIN_10},
		{"VCC_OUT_4" , GPIOD, GPIO_PIN_12},
		{"VCC_OUT_5" , GPIOD, GPIO_PIN_14},
		{"VCC_OUT_6" , GPIOG, GPIO_PIN_2 },
		{"VCC_OUT_7" , GPIOG, GPIO_PIN_4 },
		{"VCC_OUT_8" , GPIOG, GPIO_PIN_6 },
		{"VCC_OUT_9" , GPIOA, GPIO_PIN_15},
		{"VCC_OUT_10", GPIOC, GPIO_PIN_11},
		{"VCC_OUT_11", GPIOD, GPIO_PIN_0 },
		{"VCC_OUT_12", GPIOD, GPIO_PIN_2 },
		{"VCC_OUT_13", GPIOD, GPIO_PIN_4 },
		{"VCC_OUT_14", GPIOD, GPIO_PIN_6 },
		{"VCC_OUT_15", GPIOG, GPIO_PIN_9 }
};

void Update_INPUT(void){
	for(int i=0; i<16; i++){
		if(HAL_GPIO_ReadPin(GPIO_INPUT[i].port, GPIO_INPUT[i].pin)==1) data_input[i]=0;
		if(HAL_GPIO_ReadPin(GPIO_INPUT[i].port, GPIO_INPUT[i].pin)==0) data_input[i]=1;
	}
}


void Update_OUTPUT(void){
	if(gate==0){ // SET ALL
		for(int i=0; i<16; i++){
			if(value == 0){
				HAL_GPIO_WritePin(GPIO_GND_OUTPUT[i].port, GPIO_GND_OUTPUT[i].pin, 0);
				HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[i].port, GPIO_VCC_OUTPUT[i].pin, 1);
			}
			else if(value == 1){
				HAL_GPIO_WritePin(GPIO_GND_OUTPUT[i].port, GPIO_GND_OUTPUT[i].pin, 1);
				HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[i].port, GPIO_VCC_OUTPUT[i].pin, 1);
			}
			else if(value == 2){
				HAL_GPIO_WritePin(GPIO_GND_OUTPUT[i].port, GPIO_GND_OUTPUT[i].pin, 0);
				HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[i].port, GPIO_VCC_OUTPUT[i].pin, 0);
			}
		}
	}
	else{  //SET CHANNEL
		if(value == 0){
			HAL_GPIO_WritePin(GPIO_GND_OUTPUT[gate].port, GPIO_GND_OUTPUT[gate].pin, 0);
			HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[gate].port, GPIO_VCC_OUTPUT[gate].pin, 1);
		}
		else if(value == 1){
			HAL_GPIO_WritePin(GPIO_GND_OUTPUT[gate].port, GPIO_GND_OUTPUT[gate].pin, 1);
			HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[gate].port, GPIO_VCC_OUTPUT[gate].pin, 1);
		}
		else if(value == 2){
			HAL_GPIO_WritePin(GPIO_GND_OUTPUT[gate].port, GPIO_GND_OUTPUT[gate].pin, 0);
			HAL_GPIO_WritePin(GPIO_VCC_OUTPUT[gate].port, GPIO_VCC_OUTPUT[gate].pin, 0);
		}
	}
}

