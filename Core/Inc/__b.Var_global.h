#ifndef INC_B_VAR_GLOBAL_H_
#define INC_B_VAR_GLOBAL_H_
#include <stdint.h>

//RECEIVE-TRANSFER
extern uint8_t buff[64];
extern uint8_t reply[64];

//INPUT_OUTPUT
extern uint8_t data_input[16];
extern int value ;
extern int gate  ;

//TEMP_POWER
extern float Voltage, TEMP;

//BNO
extern float heading;
extern float roll;
extern float pitch;


//DAC
extern int Com_DAC;
extern int Volt_DAC;
#endif
