/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Event.h"
#include "KeyDebounce.h"
#include "Application.h"

static void Main_Loop_Task(void* param) {
  (void)param; /* avoid compiler warning */
#if PL_CONFIG_HAS_EVENTS
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
#endif

  for(;;) {
#if PL_CONFIG_HAS_KEY
	KEYDBNC_Process();
#endif
#if PL_CONFIG_HAS_EVENTS
    EVNT_HandleEvent(APP_HandleEvent,TRUE);
#endif
  }
}

void RTOS_Init(void) {
  /*! \todo Create tasks here */
  xTaskCreate(Main_Loop_Task,"Main",configMINIMAL_STACK_SIZE+50,(void*)NULL,tskIDLE_PRIORITY,(void*)NULL);
}

void RTOS_Deinit(void) {
  /* nothing needed for now */
}

#endif /* PL_CONFIG_HAS_RTOS */
