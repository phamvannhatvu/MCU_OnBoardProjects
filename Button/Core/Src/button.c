/*
 * button.c
 *
 *  Created on: Oct 6, 2023
 *      Author: ADMIN
 */


#include "button.h"
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  500;
int button1_flag = 0;
int button1long_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1long_flag == 1){
		button1long_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	button1_flag = 1;
}

void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  //Add your button here
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);

  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        button1_flag = 1;
      }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress <= 0){
        	TimeOutForKeyPress = 500;
        	if (KeyReg2 == PRESSED_STATE)
        	{
        		button1long_flag = 1;
        	}
        }
    }
  }
}

