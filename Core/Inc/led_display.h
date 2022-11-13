/*
 * led_display.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "global.h"

void LedClear();
void update7SEG(int index);
void updateBuffer_a(int number);
void updateBuffer_b(int number);
void display7SEG_a(int number);
void display7SEG_b(int number);
void display_RED_GREEN();
void display_RED_YELLOW();
void display_GREEN_RED();
void display_YELLOW_RED();

#endif /* INC_LED_DISPLAY_H_ */
