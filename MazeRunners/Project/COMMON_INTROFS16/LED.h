/*
 * LED.h
 *
 *  Created on: 1 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_LED_H_
#define SOURCES_COMMON_INTROFS16_LED_H_

#if PL_NOF_LED >= 1
	#include "LEDPin1.h"
#if PL_NOF_LED >= 2
	#include "LEDPin2.h"
#if PL_NOF_LED >= 3
	#include "LEDPin3.h"

#if PL_NOF_LED >= 1
#define LED_Neg(nr) LEDPin##nr##_NegVal();
#define LED_On()

#if PL_NOF_LED >=2
#define LED2_On()		LED_On(2);
#define LED2_Off()		LED_Off(2);
#define LED2_Neg()		LED_Neg(2);
#define LED2_Put()		LED_Put(2);
#define LED2_Get()		LED_Get(2);
#endif

#if PL_NOF_LED >=3
#define LED3_On()		LED_On(3);
#define LED3_Off()		LED_Off(3);
#define LED3_Neg()		LED_Neg(3);
#define LED3_Put()		LED_Put(3);
#define LED3_Get()		LED_Get(3);
#endif


#endif /* SOURCES_COMMON_INTROFS16_LED_H_ */
