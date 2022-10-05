/*
 * led_display.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */

#include "led_display.h"

void display7SEG(int number){
	switch (number){

		case 0:
			GPIOA->ODR = 0x0040;
			break;
		case 1:
			GPIOA->ODR = 0x0079;
			break;
		case 2:
			GPIOA->ODR = 0x0024;
			break;
		case 3:
			GPIOA->ODR = 0x0030;
			break;
		case 4:
			GPIOA->ODR = 0x0019;
			break;
		case 5:
			GPIOA->ODR = 0x0012;
			break;
		case 6:
			GPIOA->ODR = 0x0002;
			break;
		case 7:
			GPIOA->ODR = 0x0078;
			break;
		case 8:
			GPIOA->ODR = 0x0000;
			break;
		case 9:
			GPIOA->ODR = 0x0010;
			break;
		default:
			break;
	}
}
