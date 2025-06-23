#include <__b.Var_global.h>
#include "__f.GP8403.h"
#include "main.h"

#include <stdint.h>

extern I2C_HandleTypeDef hi2c3;

//DATA0 = (VOUT / 5.0) * 0xFFF
//       = (1.65 / 5.0) * 4095 ≈ 1351
#define Dev_address (0x58<<1)
uint8_t Res_channel;
uint8_t Vol[2];

//DAC
extern int COM_DAC;
extern int Volt_DAC;

void GP8403_Init(void){
	Res_channel = 0x01;
	uint8_t Vol_1_2 = 0x11; // 0x11 = 10V ; 0x00 = 5V
	HAL_I2C_Mem_Write( &hi2c3, Dev_address, Res_channel, 1, Vol_1_2, 1, 100 ); // SET ( DAC1 && DAC2 ) = 10V
}

void GP8403_Set(int COM, int Volt_DAC){
	 	 uint16_t Vol = (Volt_DAC / 5.0) * 4095;
	    uint8_t data_Vol[2];

	    data_Vol[0] = Vol & 0x0F;
	    data_Vol[1] = (Vol >> 4) & 0xFF;

	    if(COM == 1) {
	        HAL_I2C_Mem_Write(&hi2c3, Dev_address, 0x02, 1, data_Vol, 2, 100); // Gửi cho DAC1
	    }
	    else if(COM == 2) {
	        HAL_I2C_Mem_Write(&hi2c3, Dev_address, 0x04, 1, data_Vol, 2, 100); // Gửi cho DAC2
	    }
//	else{
//	...................
//	}
}
