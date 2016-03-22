/*
 * Platform.h
 *
 *  Created on: 1 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_PLATFORM_H_
#define SOURCES_COMMON_INTROFS16_PLATFORM_H_

#include "Platform_Local.h"
#include <stdint.h>

/*
#ifdef PL_IS_ROBO
	#define PL_CONFIG_NOF_LED (2)
#define PL_NOF_KEY (1)
#elif defined(PL_IS_FRDM)
	#define PL_CONFIG_NOF_LED (3)
	#define PL_NOF_KEY (7)
#else
	#error "Unknown board?"
#endif
//*/

#define PL_CONFIG_NOF_LED 		PL_LOCAL_NOF_LED
#define PL_CONFIG_NOF_KEY		PL_LOCAL_NOF_KEY


#define PL_CONFIG_HAS_EVENTS 	(1 && defined(PL_LOCAL_HAS_EVENTS))
#define PL_CONFIG_HAS_TIMER		(1 && defined(PL_LOCAL_HAS_TIMER))
#define PL_CONFIG_HAS_LED 		(1 && defined(PL_LOCAL_HAS_LED))
#define PL_CONFIG_HAS_KEY 		(1 && defined(PL_LOCAL_HAS_KEY))
#define PL_CONFIG_HAS_JOYSTICK	(1 && defined(PL_LOCAL_HAS_JOYSTICK))
#define PL_CONFIG_HAS_TRIGGER	(1 && defined(PL_LOCAL_HAS_TRIGGER))
#define PL_CONFIG_HAS_BUZZER	(1 && defined(PL_LOCAL_HAS_BUZZER))
#define PL_CONFIG_HAS_SHELL		(1 && defined(PL_LOCAL_HAS_SHELL))

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_INTROFS16_PLATFORM_H_ */
