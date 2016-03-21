#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "Event.h"
#include "WAIT1.h"
#include "Key.h"
#include "CLS1.h"


 void APP_HandleEvent(EVNT_Handle event)
  {
  	switch(event)
  	{
  	case EVNT_STARTUP:
  		//nothing;
  		break;
  	case EVENT_LED_HEARTBEAT:
  		// do nothing;
  		break;
  	case EVENT_SW1_PRESSED:
  		LED1_Neg();
  		CLS1_SendStr("SW1_Pressed", CLS1_GetStdio()->stdOut);
  		break;
  	case EVENT_SW2_PRESSED:
  	  	LED1_Off();
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
	  Key_Scan();
    EVNT_HandleEvent(APP_HandleEvent,1);
  }

  for(;;) {
    /* wait */
  }
}


