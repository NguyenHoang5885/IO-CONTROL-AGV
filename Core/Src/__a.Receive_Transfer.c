#include <__a.Receive_transfer.h>
#include "__b.Var_global.h"
#include <__c.IO_part.h>
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
extern uint8_t value ;
extern uint8_t gate  ;

//TEMP_POWER
extern uint8_t temp_power;

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
        for(int i=0; i<strlen(buff); i++){
        	if(buff[i] == 'C' && buff[i+1] == 'H'){
				gate = buff[i+2] - '0';
				value= buff[i+4] - '0';
        	}
        }
		if(gate >= 0 && gate <16 && (value == 0 || value == 1 || value == 2)){
			sprintf(reply, "SET OUTPUT CH%d %d SUCCESS\r\n",gate,value);
			Update_OUTPUT();
		}
		else{
			sprintf(reply, "NO SUPPORT\r\n");
		}
    }

	//----------------TEMP POWER---------------------------------------------------
//	else if (strcmp((char*)buff, "GET TEMP POWER") == 0) {
//	        for(int i=0; i<strlen(buff); i++){
//
//
//	        	}
//	        sprintf(reply, "TEMP POWER: %d\r\n", temp_power);
//	        }

	else{
		sprintf(reply, "NO SUPPORT\r\n");
	}
}
