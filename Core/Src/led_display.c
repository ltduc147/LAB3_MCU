/*
 * led_display.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */

#include "led_display.h"

int Buffer_7SEG_a[2] = {1, 4};
int Buffer_7SEG_b[2] = {1, 0};

void LedClear(){
	HAL_GPIO_WritePin(GPIOA, R_a_Pin| G_a_Pin| Y_a_Pin | R_b_Pin| G_b_Pin| Y_b_Pin| EN0_a_Pin| EN1_a_Pin| EN0_b_Pin| EN1_b_Pin, SET);
	GPIOB->ODR = 0xffff;
}

void display7SEG_a(int number){
	switch (number){
		case 0:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0040;
			break;
		case 1:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0079;
			break;
		case 2:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0024;
			break;
		case 3:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0030;
			break;
		case 4:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0019;
			break;
		case 5:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0012;
			break;
		case 6:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0002;
			break;
		case 7:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0078;
			break;
		case 8:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0000;
			break;
		case 9:
			GPIOB->ODR = ((GPIOB->ODR) & (0xff00)) | 0x0010;
			break;
		default:
			break;
	}
}

void display7SEG_b(int number){
	switch (number){
		case 0:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x4000;
			break;
		case 1:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x7900;
			break;
		case 2:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x2400;
			break;
		case 3:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x3000;
			break;
		case 4:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x1900;
			break;
		case 5:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x1200;
			break;
		case 6:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x0200;
			break;
		case 7:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x7800;
			break;
		case 8:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x0000;
			break;
		case 9:
			GPIOB->ODR = ((GPIOB->ODR) & (0x00ff)) | 0x1000;
			break;
		default:
			break;
	}
}

void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(EN1_a_GPIO_Port, EN1_a_Pin, SET);
			HAL_GPIO_WritePin(EN1_b_GPIO_Port, EN1_b_Pin, SET);
			display7SEG_a(Buffer_7SEG_a[0]);
			display7SEG_b(Buffer_7SEG_b[0]);
			HAL_GPIO_WritePin(EN0_a_GPIO_Port, EN0_a_Pin, RESET);
			HAL_GPIO_WritePin(EN0_b_GPIO_Port, EN0_b_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_a_GPIO_Port, EN0_a_Pin, SET);
			HAL_GPIO_WritePin(EN0_b_GPIO_Port, EN0_b_Pin, SET);
			display7SEG_a(Buffer_7SEG_a[1]);
			display7SEG_b(Buffer_7SEG_b[1]);
			HAL_GPIO_WritePin(EN1_a_GPIO_Port, EN1_a_Pin, RESET);
			HAL_GPIO_WritePin(EN1_b_GPIO_Port, EN1_b_Pin, RESET);
			break;
		default:
			break;
	}
}
void updateBuffer_a(int number){
	Buffer_7SEG_a[0] = number / 10;
	Buffer_7SEG_a[1] = number % 10;
}
void updateBuffer_b(int number){
	Buffer_7SEG_b[0] = number / 10;
	Buffer_7SEG_b[1] = number % 10;
}

void display_RED_GREEN(){
	HAL_GPIO_WritePin(GPIOA, R_a_Pin | G_b_Pin , RESET);
	HAL_GPIO_WritePin(GPIOA, G_a_Pin | Y_a_Pin | R_b_Pin | Y_b_Pin , SET);
}
void display_RED_YELLOW(){
	HAL_GPIO_WritePin(GPIOA, R_a_Pin | Y_b_Pin , RESET);
	HAL_GPIO_WritePin(GPIOA, G_a_Pin | Y_a_Pin | R_b_Pin | G_b_Pin , SET);
}

void display_GREEN_RED(){
	HAL_GPIO_WritePin(GPIOA, G_a_Pin | R_b_Pin , RESET);
	HAL_GPIO_WritePin(GPIOA, R_a_Pin | Y_a_Pin | G_b_Pin | Y_b_Pin , SET);
}

void display_YELLOW_RED(){
	HAL_GPIO_WritePin(GPIOA, Y_a_Pin | R_b_Pin , RESET);
	HAL_GPIO_WritePin(GPIOA, R_a_Pin | G_a_Pin | G_b_Pin | Y_b_Pin , SET);
}

