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

#endif /* SOURCES_COMMON_INTROFS16_LED_H_ */
