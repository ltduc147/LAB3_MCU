/*
 * fsm_green_change.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Admin
 */

#include "fsm_green_change.h"

void fsm_green_change_run(){
	switch (status){
		case SET_GREEN_TIME:
			if (timer1_flag == 1){
				setTimer1(500);
				HAL_GPIO_TogglePin(GPIOA, G_a_Pin| G_b_Pin);
			}
			updateBuffer_a(temp_value);
			updateBuffer_b(mode);
			if (isButtonPress(1)){
				temp_value++;
				if (temp_value > 99){
					temp_value = 1;
				}
			}
			if (isButtonPress(2)){
				RED_TIME_b += temp_value - GREEN_TIME_a;
				GREEN_TIME_a = temp_value;
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(GREEN_TIME_b * 1000);
				mode = 1;
				number_display_a = RED_TIME_a;
				number_display_b = GREEN_TIME_b;
				setTimer2(10);
				status = RED_GREEN;
			}
					break;
				default:
					break;
			}
}
