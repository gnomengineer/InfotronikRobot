/*
 * Key.c
 *
 *  Created on: 14 Mar 2016
 *      Author: daniel foehn
 */

#include "Platform.h"
#if PL_CONFIG_HAS_KEY
	#include "Key.h"
#endif
#if PL_CONFIG_HAS_EVENTS
	#include "Event.h"
#endif
#if PL_CONFIG_IS_ROBO_V2
	#include "PORT_PDD.h"
#endif

void Key_Scan(void){
#if PL_CONFIG_NOF_KEYS >= 1
	if(Key1_Get()){
		EVNT_SetEvent(EVENT_SW1_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 2
	if(Key2_Get()){
		EVNT_SetEvent(EVENT_SW2_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 3
	if(Key3_Get()){
		EVNT_SetEvent(EVENT_SW3_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 4
	if(Key4_Get()){
		EVNT_SetEvent(EVENT_SW4_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 5
	if(Key5_Get()){
		EVNT_SetEvent(EVENT_SW5_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 6
	if(Key6_Get()){
		EVNT_SetEvent(EVENT_SW6_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEYS >= 7
	if(Key7_Get()){
		EVNT_SetEvent(EVENT_SW7_PRESSED);
	}
#endif
}

void KEY_Init(){
#if PL_CONFIG_IS_ROBO_V2
	/* enable and turn on pull-up resistor for PTA14 */
	PORT_PDD_SetPinPullSelect(PORTA_BASE_PTR, 14, PORT_PDD_PULL_UP);
	PORT_PDD_SetPinPullEnable(PORTA_BASE_PTR, 14, PORT_PDD_PULL_ENABLE);
#endif

}

void KEY_Deinit(){
	// do nothing
}
