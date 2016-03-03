/*
 * LED.h
 *
 *  Created on: 1 Mar 2016
 *      Author: Daniel Föhn
 */

#ifndef SOURCES_COMMON_INTROFS16_LED_H_
#define SOURCES_COMMON_INTROFS16_LED_H_

#if PL_NOF_LED >= 1
	#include "LEDPin1.h"
#endif
#if PL_NOF_LED >= 2
	#include "LEDPin2.h"
#endif
#if PL_NOF_LED >= 3
	#include "LEDPin3.h"
#endif

#if PL_NOF_LED >= 1
	#define LED_Neg(nr) LEDPin##nr##_NegVal();
	#define LED_On(nr) LEDPin##nr##_ClrVal();
	#define LED_Off(nr) LEDPin##nr##_SetVal();
	#define LED_Get(nr) LEDPin##nr##_GetVal();
	#define LED_Put(nr) LEDPin##nr##_PutVal();
#endif

#if PL_NOF_LED >= 1
	#define LED1_Neg() LED_Neg(1)
	#define LED1_On() LED_On(1)
	#define LED1_Off() LED_Off(1)
	#define LED1_Get() LED_Get(1)
	#define LED1_Put() LED_Put(1)
#endif

void LED_Init(void);
void LED_Deinit(void);

#endif /* SOURCES_COMMON_INTROFS16_LED_H_ */
