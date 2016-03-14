#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "Event.h"
#include "WAIT1.h"

 void APP_HandleEvent(EVNT_Handle event)
  {
  	switch(event)
  	{
  	case EVNT_STARTUP:
  		//nothing;
  		break;
  	case EVENT_LED_HEARTBEAT:
  		LED1_Neg();
  		break;
  	case EVENT_SW1_PRESSED:
  		//do something
  		break;
  	default:
  		//do nothing
  		break;
  	}
  }

void APP_Start(void) {
  PL_Init();
  /* init: turn off */



  for(;;) {
    EVNT_HandleEvent(APP_HandleEvent,1);
  }

  for(;;) {
    /* wait */
  }
}


