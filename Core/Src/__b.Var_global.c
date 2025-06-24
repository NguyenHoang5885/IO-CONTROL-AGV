#include <__b.Var_global.h>

//RECEIVE - TRANSFER HID
uint8_t buff[64];
uint8_t reply[64];

//INPUT_OUTPUT
uint8_t data_input[16];
int value =0;
int gate  =0;

//TEMP_POWER
float Voltage, TEMP;

//BNO
float heading;
float roll;
float pitch;
//DAC
int Com_DAC;
int Volt_DAC;
