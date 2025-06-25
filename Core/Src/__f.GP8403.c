#include <__b.Var_global.h>
#include "__f.GP8403.h"
#include "main.h"

#include <stdint.h>

extern I2C_HandleTypeDef hi2c3;

//DATA0 = (VOUT / 5.0)  * 0xFFF         // max 5V
//      = (1.65 / 5.0)  * 4095 ≈ 1351
//DATA0 = (VOUT / 10.0) * 0xFFF         // max 10V

#define Dev_address (0x58<<1)
uint8_t Res_channel;
//uint8_t Vol[2];

//DAC
extern int Com_DAC;
extern int Volt_DAC;

void GP8403_Init(void){
	Res_channel = 0x01;
	uint8_t Vol_1_2 = 0x11; // 0x11 = 10V ; 0x00 = 5V
	HAL_I2C_Mem_Write( &hi2c3, Dev_address, Res_channel, 1, &Vol_1_2, 1, 100 ); // SET ( DAC1 && DAC2 ) = 10V
}

void GP8403_Set(int COM_DAC, int VOLT_DAC){

	uint16_t Vol = (uint16_t)((float)VOLT_DAC / 10.0f * 4095.0f);
	uint8_t data_Vol[4];

	// Registor_GP8403 = START | DEVICE_ADDR_W | REGISTER_ADDR | DATA_LOW (D3–D0 << 4) | DATA_HIGH (D11–D4) | STOP
	// VD_Data: 3333 2222 1111 => data[2] = 1111 0000, 3333 2222

	if(COM_DAC == 0) {
		data_Vol[0] = (Vol & 0x0F)<<4;
		data_Vol[1] = (Vol >> 4) & 0xFF;
		HAL_I2C_Mem_Write(&hi2c3, Dev_address, 0x02, 1, data_Vol, 2, 100);
	}
	else if(COM_DAC == 1) {
		data_Vol[0] = (Vol & 0x0F)<<4;
		data_Vol[1] = (Vol >> 4) & 0xFF;
	    HAL_I2C_Mem_Write(&hi2c3, Dev_address, 0x04, 1, data_Vol, 2, 100);
	}

	else if(COM_DAC == 2) {
		data_Vol[0] = (Vol & 0x0F)<<4;
		data_Vol[1] = (Vol >> 4) & 0xFF;
		data_Vol[2] = (Vol & 0x0F)<<4;
		data_Vol[3] = (Vol >> 4) & 0xFF;
		HAL_I2C_Mem_Write(&hi2c3, Dev_address, 0x02, 1, data_Vol, 4, 100);
	}
}
