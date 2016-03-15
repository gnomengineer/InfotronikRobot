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

void Key_Scan(void){
#if PL_CONFIG_NOF_KEY >= 1
	if(Key1_Get()){
		EVNT_SetEvent(EVENT_SW1_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 2
	if(Key2_Get()){
		EVNT_SetEvent(EVENT_SW2_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 3
	if(Key3_Get()){
		EVNT_SetEvent(EVENT_SW3_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 4
	if(Key4_Get()){
		EVNT_SetEvent(EVENT_SW4_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 5
	if(Key5_Get()){
		EVNT_SetEvent(EVENT_SW5_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 6
	if(Key6_Get()){
		EVNT_SetEvent(EVENT_SW6_PRESSED);
	}
#endif

#if PL_CONFIG_NOF_KEY >= 7
	if(Key7_Get()){
		EVNT_SetEvent(EVENT_SW7_PRESSED);
	}
#endif
}

void KEY_Init(){
	// do nothing
}

void KEY_Deinit(){
	// do nothing
}
