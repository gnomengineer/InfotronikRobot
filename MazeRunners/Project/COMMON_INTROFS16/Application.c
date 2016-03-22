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
  		LED1_On();//nothing;
  		break;
  	case EVENT_LED_HEARTBEAT:
  		// do nothing;
  		break;
  	case EVENT_SW1_PRESSED:
  		LED1_Neg();
  		CLS1_SendStr("SW1_Pressed\n\r", CLS1_GetStdio()->stdOut);
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
#if PL_CONFIG_HAS_EVENTS
  EVNT_SetEvent(EVNT_STARTUP);
#endif

  CLS1_SendStr("Hello World\n\r",CLS1_GetStdio()->stdOut);
  for(;;) {
#if PL_CONFIG_HAS_KEY
	Key_Scan();
#endif
#if PL_CONFIG_HAS_EVENTS
    EVNT_HandleEvent(APP_HandleEvent,1);
#endif
    WAIT1_Waitms(50);
  }

  for(;;) {
    /* wait */
  }
}


