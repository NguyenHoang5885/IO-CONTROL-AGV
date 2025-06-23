#include "main.h"
#include <__b.Var_global.h>
#include "__e.BNO055.h"

extern I2C_HandleTypeDef hi2c2;

#define BNO_address  (0x28 << 1)
const uint8_t RES_PAGE_ID  = 0x07;
const uint8_t RES_OPR_MODE = 0x3D;
const uint8_t RES_PWR_MODE = 0x3E;
const uint8_t RES_UNIT_SEL = 0x3B;

// res_read
const uint8_t RES_CHIP_ID     = 0X00;
const uint8_t RES_EULER_H_LSB = 0x1A;
//
extern float heading;
extern float roll;
extern float pitch;
uint8_t LSB_value[6];

void BNO055_Init(void){

	HAL_GPIO_WritePin(BNO_PS2_GPIO_Port, BNO_PS2_Pin, 0);
	HAL_GPIO_WritePin(BNO_PS1_GPIO_Port, BNO_PS1_Pin, 0); HAL_Delay(500);

	HAL_GPIO_WritePin(BNO_RST_GPIO_Port, BNO_RST_Pin, 0); HAL_Delay(500);
	HAL_GPIO_WritePin(BNO_RST_GPIO_Port, BNO_RST_Pin, 1); HAL_Delay(500);


	uint8_t page = 0x00;
	HAL_I2C_Mem_Write(&hi2c2, BNO_address, (uint8_t)RES_PAGE_ID , 1, &page , 1, 500);

	uint8_t mode_init = 0x00;
	HAL_I2C_Mem_Write(&hi2c2, BNO_address, (uint8_t)RES_OPR_MODE, 1, &mode_init , 1, 500); // Set to CONFIG_MODE
	HAL_Delay(100);

	uint8_t pwr = 0x00;
	HAL_I2C_Mem_Write(&hi2c2, BNO_address, (uint8_t)RES_PWR_MODE, 1, &pwr, 1, 500); // Set Full Power

	uint8_t mode_ndof = 0x0C;
	HAL_I2C_Mem_Write(&hi2c2, BNO_address, (uint8_t)RES_OPR_MODE, 1, &mode_ndof, 1, 500); // Set to NDOF mode
	HAL_Delay(50);

	uint8_t unit = 0x00;
	HAL_I2C_Mem_Write(&hi2c2, BNO_address, (uint8_t)RES_UNIT_SEL, 1, &unit , 1, 500);  // Set Unit
	HAL_Delay(50);
}

void BNO055_Getvalue(void){
	HAL_I2C_Mem_Read(&hi2c2, BNO_address, RES_EULER_H_LSB, 1, LSB_value, 6, 500) ;

	int16_t heading_raw = ((uint16_t)LSB_value[1]<<8) | LSB_value[0];
	int16_t roll_raw    = ((uint16_t)LSB_value[3]<<8) | LSB_value[2];
	int16_t pitch_raw   = ((uint16_t)LSB_value[5]<<8) | LSB_value[4];

	heading =  (float)heading_raw/16.0f;
	roll    =  (float)roll_raw   /16.0f;
	pitch   =  (float)pitch_raw  /16.0f;

}
