#include "Platform.h"

/* user includes */
#if PL_CONFIG_HAS_LED == 1
	#include "LED.h"
#endif
#if PL_CONFIG_HAS_KEY
	#include "Key.h"
#endif
#if PL_CONFIG_HAS_EVENTS
	#include "Event.h"
#endif
#if PL_CONFIG_HAS_KEY
	#include "Key.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
	#include "KeyDebounce.h"
#endif
#if PL_CONFIG_HAS_RTOS
	#include "RTOS.h"
#endif
#if PL_CONFIG_HAS_SHELL
	#include "Shell.h"
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
	#include "ShellQueue.h"
#endif
#if PL_CONFIG_HAS_MOTOR
	#include "Motor.h"
#endif
#if PL_CONFIG_HAS_REFLECTANCE
	#include "Reflectance.h"
#endif
#if PL_CONFIG_HAS_PID
	#include "Pid.h"
#endif
#if PL_CONFIG_HAS_DRIVE
	#include "Drive.h"
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
	#include "LineFollow.h"
#endif
#if PL_CONFIG_HAS_RADIO
	#include "RNet_App.h"
#endif
#if PL_CONFIG_HAS_REMOTE
	#include "Remote.h"
#endif

/* Platform initialization */
void PL_Init(void){
#if PL_CONFIG_HAS_LED
	LED_Init();
#endif
#if PL_CONFIG_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_CONFIG_HAS_KEY
	KEY_Init();
#endif
#if PL_CONFIG_HAS_DEBOUNCE
	KEYDBNC_Init();
#endif
#if PL_CONFIG_HAS_RTOS
	RTOS_Init();
#endif
#if PL_CONFIG_HAS_SHELL
	SHELL_Init();
#endif
#if PL_CONFIG_HAS_SHELL_QUEUE
	SQUEUE_Init();
#endif
#if PL_CONFIG_HAS_SEMAPHORE
	SEM_Init();
#endif
#if PL_CONFIG_HAS_MOTOR
	MOT_Init();
#endif
#if PL_CONFIG_HAS_REFLECTANCE
	REF_Init();
#endif
#if PL_CONFIG_HAS_PID
	PID_Init();
#endif
#if PL_CONFIG_HAS_DRIVE
	DRV_Init();
#endif
#if PL_CONFIG_HAS_LINE_FOLLOW
	LF_Init();
#endif
#if PL_CONFIG_HAS_RADIO
	RNETA_Init();
#endif
#if PL_CONFIG_HAS_REMOTE
	REMOTE_Init();
#endif
}

void PL_Deinit(void){
#if PL_CONFIG_HAS_LED
	LED_Deinit();
	EVNT_Deinit();
#endif
#if PL_CONFIG_HAS_SHELL
	SHELL_Deinit();
#endif
}
