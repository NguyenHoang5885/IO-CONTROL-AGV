#include <__a.Receive_transfer.h>
#include "__b.Var_global.h"
#include <__c.IO_part.h>
#include "__d.LM35.h"
#include "__e.BNO055.h"
#include "main.h"
#include "usbd_ioreq.h"
#include "__HID_address.h"
#include "usbd_customhid.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//------------VALUE--------------------------
//RECEIVE-TRANSFER
extern uint8_t buff[64];
extern uint8_t reply[64];

//INPUT_OUTPUT
extern uint8_t data_input[16];
extern int     value ;
extern int     gate  ;

//TEMP_POWER
extern float Voltage,TEMP;
//BNO
extern float heading;
extern float roll;
extern float pitch;

//DAC
extern int Com_DAC;
extern int Volt_DAC;


//-------------FUNCTION----------------------
void Read_HID(void){
	value=0;
	gate=0;
	memset(reply,0,strlen(reply));

	buff[27] = '\0';
	//----------------CHECK CONNECT-----------------------------------------------
	if(strcmp(buff,"CHECK CONNECT\r\n")==0){
		sprintf(reply, "CONNECT SUCCESS\r\n");
	}
	//----------------INPUT--------------------------------------------------------
	else if(strcmp(buff,"GET STATE INPUT\r\n")==0){
		Update_INPUT();
		sprintf(reply, "INPUT: ");
		for(int i=0; i <16; i++){
			char temp[4];
			sprintf(temp, "|%d ",data_input[i]);
			strcat(reply,temp);
		}
		strcat(reply,"\r\n");
	}

	//----------------OUTPUT------------------------------------------------------
	else if(strncmp((char*)buff, "SET OUTPUT ALL" , 14)==0){
		if(sscanf((char*)buff,"SET OUTPUT ALL %hhu\r\n", &value)==1){
			if(value == 0 || value == 1 || value == 2){
				sprintf(reply, "SET OUTPUT ALL %d SUCCESS\r\n", value);
			}
			else{
				sprintf(reply, "NO SUPPORT\r\n");
			}
		}
		Update_OUTPUT();
	}
	else if (strncmp((char*)buff, "SET OUTPUT CH", 13) == 0) {
		if(sscanf((char*)buff,"SET OUTPUT CH%d %d\r\n", &gate, &value)==2){
				if(value == 0 || value == 1 || value == 2){
					sprintf(reply, "SET OUTPUT CH%d %d SUCCESS\r\n", gate, value);
				}
				else{
					sprintf(reply, "NO SUPPORT\r\n");
				}
			}
			Update_OUTPUT();
    }

	//----------------TEMP POWER---------------------------------------------------
	else if (strcmp((char*)buff, "GET TEMP POWER\r\n") == 0) {
			GET_TEMP_POWER();
	        sprintf(reply, "TEMP POWER: %.2f\r\n", TEMP);
	}
	//----------------GET BNO VALUE------------------------------------------------
	else if (strcmp((char*)buff, "GET XYZ\r\n") == 0) {
		    sprintf(reply, "X: %.2f | Y: %.2f | Z: %.2f\r\n", heading, roll, pitch);
	}
	//----------------SET ADC------------------------------------------------------

	else if (strncmp((char*)buff, "SET DAC CH",10) == 0) {
		if(sscanf((char*)buff,"SET DAC CH%d %dV\r\n", &Com_DAC, &Volt_DAC)==2){
			GP8403_Set(Com_DAC, Volt_DAC);
			sprintf(reply, "SET DAC CH%d %d Volt SUCCESS\r\n", Com_DAC, Volt_DAC);
		}
	}
	else{
		sprintf(reply, "NO SUPPORT\r\n");
	}
}
