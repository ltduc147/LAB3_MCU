/*
 * fsm_yellow_change.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Admin
 */

#include "fsm_yellow_change.h"

void fsm_yellow_change_run(){
	switch (status){
			case SET_YELLOW_TIME:
				if (timer1_flag == 1){
					setTimer1(500);
					HAL_GPIO_TogglePin(GPIOA, Y_a_Pin| Y_b_Pin);
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
					RED_TIME_b += temp_value - YELLOW_TIME_a;
					YELLOW_TIME_a = temp_value;
				}
				if (isButtonPress(0)){
					LedClear();
					setTimer1(500);
					temp_value = GREEN_TIME_a;
					mode = 4;
					status = SET_GREEN_TIME;
				}
				break;
			default:
				break;
		}
}
