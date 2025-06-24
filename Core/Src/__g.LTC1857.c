#include "__g.LTC1857.h"
#include "main.h"

extern SPI_HandleTypeDef hspi1;

uint8_t LTC_CH0 = 0x88;
uint8_t LTC_CH5 = 0xAC;
uint8_t ADC_Recv[2];
int dem=0;
void LTC1857_Getvalue(void){

	 // 1. Chu kỳ đầu tiên: gửi lệnh CHx
	    HAL_GPIO_WritePin(ADC_SPI_CS_GPIO_Port, ADC_SPI_CS_Pin, GPIO_PIN_RESET);
	    HAL_SPI_Transmit(&hspi1, &LTC_CH0, 1, 100);
	    HAL_GPIO_WritePin(ADC_SPI_CS_GPIO_Port, ADC_SPI_CS_Pin, GPIO_PIN_SET);

	    // 2. Tạo xung CONVERT
	    HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_SET);
	    for(volatile int i = 0; i < 1000; i++); // delay ngắn
	    HAL_GPIO_WritePin(ADC_CONVERT_GPIO_Port, ADC_CONVERT_Pin, GPIO_PIN_RESET);

	    // 3. Đợi BUSY xong
	    while (HAL_GPIO_ReadPin(ADC_BUSY_GPIO_Port, ADC_BUSY_Pin) == GPIO_PIN_RESET);

	    // 4. Chu kỳ thứ 2: gửi lệnh lại (hoặc lệnh kênh tiếp theo)
	    HAL_GPIO_WritePin(ADC_SPI_CS_GPIO_Port, ADC_SPI_CS_Pin, GPIO_PIN_RESET);
	    HAL_SPI_TransmitReceive(&hspi1, &LTC_CH0, ADC_Recv, 2, 100);
	    HAL_GPIO_WritePin(ADC_SPI_CS_GPIO_Port, ADC_SPI_CS_Pin, GPIO_PIN_SET);


	//return (ADC_Recv[0]<<8) | ADC_Recv[1];
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
