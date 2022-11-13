/*
 * input_reading.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "input_reading.h"

#define NUM_OF_BUTTONS 		3
#define TIME_FOR_LONGPRESS  300
#define BUTTON_PRESSED		GPIO_PIN_RESET
#define BUTTON_RELEASED 	GPIO_PIN_SET

int key1[NUM_OF_BUTTONS];
int key2[NUM_OF_BUTTONS];
int keybuffer[NUM_OF_BUTTONS];
int counter_Button[NUM_OF_BUTTONS];
int flagforLongPress[NUM_OF_BUTTONS];
int flagforPress[NUM_OF_BUTTONS];

void keyprocess(){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

int isButtonPress(int index){
	if (flagforPress[index] == 1){
		flagforPress[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPress(int index){
	return (flagforLongPress[index] == 1);
}

void button_read(){
	for (int i = 0 ; i < NUM_OF_BUTTONS; i++){
		key1[i] = key2[i];
		if (i == 0){
			key2[i] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
		}
		if (i == 1){
			key2[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
		}
		if (i == 2){
			key2[i] = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
		}

		if (key2[i] == key1[i]){
				if (keybuffer[i] != key2[i]){
					keybuffer[i] = key2[i];
					if (keybuffer[i] == BUTTON_PRESSED){
						flagforPress[i] = 1;
						keyprocess();
					} else {
						flagforLongPress[i] = 0;
						counter_Button[i] = 0;
					}
				} else {
					if (keybuffer[i] == BUTTON_PRESSED){
						if (counter_Button[i] < TIME_FOR_LONGPRESS ){
							counter_Button[i]++;
						} else {
							flagforLongPress[i] = 1;
						}
					}
				}
		}
	}
}
