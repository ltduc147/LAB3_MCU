/*
 * fsm_normal.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Admin
 */


#include "fsm_normal.h"

void fsm_normal_run(){
	switch (status){
		case INIT:
			status = RED_GREEN;
			setTimer1(GREEN_TIME_b * 1000);
			number_display_a = RED_TIME_a;
			number_display_b = GREEN_TIME_b;
			updateBuffer_a(number_display_a);
			updateBuffer_b(number_display_b);
			setTimer2(10);
			break;
		case RED_GREEN:
			display_RED_GREEN();
			if (timer2_flag == 1){
				setTimer2(1000);
				updateBuffer_a(number_display_a--);
				updateBuffer_b(number_display_b--);

			}
			if (timer1_flag == 1){
				setTimer1(YELLOW_TIME_b * 1000);
				number_display_b = YELLOW_TIME_b;
				status = RED_YELLOW;
				setTimer2(10);
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(500);
				temp_value = RED_TIME_a;
				mode = 2;
				status = SET_RED_TIME;
			}
			break;
		case RED_YELLOW:
			display_RED_YELLOW();

			if (timer2_flag == 1){
				setTimer2(1000);
				updateBuffer_a(number_display_a--);
				updateBuffer_b(number_display_b--);
			}

			if (timer1_flag == 1){
				setTimer1(GREEN_TIME_a * 1000);
				number_display_a = GREEN_TIME_a;
				number_display_b = RED_TIME_b;
				status = GREEN_RED;
				setTimer2(10);
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(500);
				temp_value = RED_TIME_a;
				mode = 2;
				status = SET_RED_TIME;
			}

			break;
		case GREEN_RED:
			display_GREEN_RED();
			if (timer2_flag == 1){
				setTimer2(1000);
				updateBuffer_a(number_display_a--);
				updateBuffer_b(number_display_b--);
			}

			if (timer1_flag == 1){
				setTimer1(YELLOW_TIME_a * 1000);
				number_display_a = YELLOW_TIME_a;
				status = YELLOW_RED;
				setTimer2(10);
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(500);
				temp_value = RED_TIME_a;
				mode = 2;
				status = SET_RED_TIME;
			}
			break;
		case YELLOW_RED:
			display_YELLOW_RED();
			if (timer2_flag == 1){
				setTimer2(1000);
				updateBuffer_a(number_display_a--);
				updateBuffer_b(number_display_b--);
			}
			if (timer1_flag == 1){
				setTimer1(GREEN_TIME_b * 1000);
				number_display_a = RED_TIME_a;
				number_display_b = GREEN_TIME_b;
				status = RED_GREEN;
				setTimer2(10);
			}
			if (isButtonPress(0)){
				LedClear();
				setTimer1(500);
				temp_value = RED_TIME_a;
				mode = 2;
				status = SET_RED_TIME;
			}
			break;
		default:
			break;
	}

}
