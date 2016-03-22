/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#include "Event.h"
#include "LED.h"

void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  /*! \todo Add code for a blinking LED here */
	static int noT = 0;
	#define BLINK_TIME_MS 2000

	noT++;
	if(noT % (BLINK_TIME_MS / TMR_TICK_MS) == 0)
	{
		TRG_AddTick();

	}
}

void TMR_Init(void) {
}

void TMR_Deinit(void) {
}

#endif /*PL_HAS_TIMER*/
