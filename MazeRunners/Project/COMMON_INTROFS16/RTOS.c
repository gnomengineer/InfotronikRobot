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
#include "Key.h"
#include "Application.h"

static void AppTask(void* param) {
  (void)param; /* avoid compiler warning */
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */


  for(;;) {
#if PL_CONFIG_HAS_KEY
	KEYDBNC_Process();
#endif
#if PL_CONFIG_HAS_EVENTS
    EVNT_HandleEvent(APP_HandleEvent,1);
#endif
    WAIT1_Waitms(50);
  }
}

void RTOS_Run(void) {
  /** set your tasks here **/

  FRTOS1_vTaskStartScheduler();  /* does usually not return! */
}

void RTOS_Init(void) {
  /*! \todo Create tasks here */
}

void RTOS_Deinit(void) {
  /* nothing needed for now */
}

#endif /* PL_CONFIG_HAS_RTOS */
