#include "Platform.h"

#if PL_CONFIG_HAS_LED == 1
	#include "LED.h"
#endif
#if PL_CONFIG_HAS_KEY
	#include "Key.h"
#endif
#if PL_CONFIG_HAS_EVENTS
	#include "Event.h"
#endif

void PL_Init(void){
#if PL_CONFIG_HAS_LED
	LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_CONFIG_HAS_KEY
	//Key_Init();
#endif
#if PL_CONFIG_HAS_RTOS
	RTOS_Init();
#endif

}

void PL_Deinit(void){
#if PL_CONFIG_HAS_LED
	LED_Deinit();
	EVNT_Deinit();
#endif
}
