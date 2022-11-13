/*
 * fsm_red_change.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Admin
 */

#include "fsm_red_change.h"

void fsm_red_change_run(){
	switch (status){
		case SET_RED_TIME:
			if (timer1_flag == 1){
				setTimer1(500);
				HAL_GPIO_TogglePin(GPIOA, R_a_Pin| R_b_Pin);
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
				GREEN_TIME_b += temp_value - RED_TIME_a;
				RED_TIME_a = temp_value;
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(500);
				temp_value = YELLOW_TIME_a;
				mode = 3;
				status = SET_YELLOW_TIME;
			}
			break;
		default:
			break;
	}
}
