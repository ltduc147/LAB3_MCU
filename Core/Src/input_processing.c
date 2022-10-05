/*
 * input_processing.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */


#include "main.h"
#include "input_reading.h"

int flag = 0;
enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;
void fsm_for_input_processing(void){
	switch(buttonState){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			buttonState = BUTTON_PRESSED;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		HAL_GPIO_WritePin(GPIOA, Led_Pin, SET);
		flag = 1;
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(0)){
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		}
		//todo
		if (flag == 1){
			number_display++;
			if (number_display > 9){
				number_display = 0;
			}
			display7SEG(number_display);
			flag = 0;
		}
		break;
	}
}
