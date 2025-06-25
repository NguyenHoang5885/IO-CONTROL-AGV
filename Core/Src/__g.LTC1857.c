#include "__g.LTC1857.h"
#include "main.h"

extern SPI_HandleTypeDef hspi1;

uint8_t LTC_CH0[2] = {0x8C, 0x00};  // 10001100 00000000
uint8_t LTC_CH5[2] = {0xEC, 0x00};  // 11011100 00000000
uint8_t ADC_Recv_Raw[2];
uint16_t ADC_Recv,voltage;

void LTC1857_Init(){

}

float LTC1857_Getvalue(void){
	HAL_GPIO_WritePin(ADC_SPI_CS_GPIO_Port, ADC_SPI_CS_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_RESET);
	while (HAL_GPIO_ReadPin(ADC_BUSY_GPIO_Port, ADC_BUSY_Pin) == GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi1, LTC_CH5, ADC_Recv_Raw, 2, 100);


	HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_RESET);
	while (HAL_GPIO_ReadPin(ADC_BUSY_GPIO_Port, ADC_BUSY_Pin) == GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi1, LTC_CH5, ADC_Recv_Raw, 2, 100);

	ADC_Recv = (ADC_Recv_Raw[0] << 8) | ADC_Recv_Raw[1];
	ADC_Recv >>= 4;
	voltage  = ( ADC_Recv * 10000 ) / 4095;
	return voltage/1000;
}

//#define ADC_SPI_CS_Pin GPIO_PIN_4
//#define ADC_SPI_CS_GPIO_Port GPIOA
//#define ADC_SPI_SCK_Pin GPIO_PIN_5
//#define ADC_SPI_SCK_GPIO_Port GPIOA
//#define ADC_SPI_MISO_Pin GPIO_PIN_6
//#define ADC_SPI_MISO_GPIO_Port GPIOA
//#define ADC_SPI_MOSI_Pin GPIO_PIN_7
//#define ADC_SPI_MOSI_GPIO_Port GPIOA
//#define ADC_CONVERT_Pin GPIO_PIN_4
//#define ADC_CONVERT_GPIO_Port GPIOC
//#define ADC_BUSY_Pin GPIO_PIN_5
//#define ADC_BUSY_GPIO_Port GPIOC
