/*
 * global.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#define INIT				0

#define RED_GREEN			1
#define RED_YELLOW			2
#define GREEN_RED			3
#define YELLOW_RED			4

#define SET_RED_TIME		5
#define SET_GREEN_TIME		6
#define SET_YELLOW_TIME		7

extern int GREEN_TIME_a;
extern int RED_TIME_a;
extern int YELLOW_TIME_a;
extern int GREEN_TIME_b;
extern int RED_TIME_b;
extern int YELLOW_TIME_b;

extern int number_display_a;
extern int number_display_b;
extern int status;
extern int mode;
extern int temp_value;

#endif /* INC_GLOBAL_H_ */
