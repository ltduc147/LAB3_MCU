/*
 * timer.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */

#include "main.h"
#include "input_reading.h"
#include "timer.h"

#define CYCLE 10

int timer1_count = 0;
int timer1_flag = 0;

int timer2_count = 0;
int timer2_flag = 0;

int timer3_count = 0;
int timer3_flag = 0;

void setTimer1(int duration){
	timer1_flag = 0;
	timer1_count = duration / CYCLE;
}

void setTimer2(int duration){
	timer2_flag = 0;
	timer2_count = duration / CYCLE;
}

void setTimer3(int duration){
	timer3_flag = 0;
	timer3_count = duration / CYCLE;
}

void timer_run(){
	if (timer1_count > 0){
		timer1_count--;
		if (timer1_count == 0){
			timer1_flag = 1;
		}
	}
	if (timer2_count > 0){
			timer2_count--;
			if (timer2_count == 0){
				timer2_flag = 1;
			}
		}
	if (timer3_count > 0){
			timer3_count--;
			if (timer3_count == 0){
				timer3_flag = 1;
			}
		}

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		timer_run();
		button_read();
	}
}
