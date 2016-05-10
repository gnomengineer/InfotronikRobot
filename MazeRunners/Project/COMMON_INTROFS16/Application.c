#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "Event.h"
#include "WAIT1.h"
#include "Key.h"
#include "CLS1.h"
#include "Buzzer.h"
#include "Tunes.h"
#include "FRTOS1.h"
#include "Shell.h"
#include "RStdIO.h"
#if PL_CONFIG_IS_ROBO_V2
	#include "PORT_PDD.h"
#endif
static int tune_counter = 0;

 void APP_HandleEvent(EVNT_Handle event)
  {
  	switch(event)
  	{
  	case EVNT_STARTUP:
  		LED1_On();//nothing;
#if PL_CONFIG_HAS_BUZZER
  		BUZ_Beep(400,200);
#endif
  		break;
  	case EVENT_LED_HEARTBEAT:
  		//LED1_Neg();
  		break;
  	case EVENT_SW1_PRESSED:
  		LED2_Neg();
#if PL_CONFIG_HAS_BUZZER && 0
		BUZ_PlayTune(MARIO);
#endif
#if PL_CONFIG_HAS_SHELL
		//CLS1_SendStr("SW1_Pressed\n\r", CLS1_GetStdio()->stdOut);
		SHELL_SendString("SW1 Pressed\n\r");
#endif
#if PL_CONFIG_IS_FRDM
		//@TODO start maze
#endif
  		break;

#if PL_CONFIG_IS_FRDM
  	case EVENT_SW2_PRESSED:
  	  	LED1_Neg();
		//@TODO set 'right-hand' algorithm
  	  	SHELL_SendString("SW2 Pressed\n\r");
  	  	break;
  	case EVENT_SW3_PRESSED:
		//@TODO turn off motors
  		SHELL_SendString("SW3 Pressed\n\r");
  		break;
  	case EVENT_SW4_PRESSED:
		//@TODO set 'left-hand' algorithm
  		SHELL_SendString("SW4 Pressed\n\r");
  		break;
  	case EVENT_SW5_PRESSED:
		//@TODO start line follow
  		SHELL_SendString("SW5 Pressed\n\r");
  		break;
  	case EVENT_SW6_PRESSED:
  		//@TODO toggle remote
  		SHELL_SendString("SW6 Pressed\n\r");
  		break;
  	case EVENT_SW7_PRESSED:
  		SHELL_SendString("SW7 Pressed\n\r");
#endif
  		break;
  	case EVENT_SW1_LPRESSED:
#if PL_CONFIG_HAS_BUZZER && 0
  		if(tune_counter < NOF_TUNES)
  		{
  			BUZ_PlayTune(tune_counter);
  			tune_counter++;
  		}
  		else
  		{
  			tune_counter = 0;
  		}
#endif
  		SHELL_SendString("Long Press\n\r");
  	default:
  		//do nothing
  		break;
  	}
  }

void APP_Start(void) {
#if PL_CONFIG_IS_ROBO_V2
	  /* pull-ups for Quadrature Encoder Pins */
	  PORT_PDD_SetPinPullSelect(PORTC_BASE_PTR, 10, PORT_PDD_PULL_UP);
	  PORT_PDD_SetPinPullEnable(PORTC_BASE_PTR, 10, PORT_PDD_PULL_ENABLE);
	  PORT_PDD_SetPinPullSelect(PORTC_BASE_PTR, 11, PORT_PDD_PULL_UP);
	  PORT_PDD_SetPinPullEnable(PORTC_BASE_PTR, 11, PORT_PDD_PULL_ENABLE);
	  PORT_PDD_SetPinPullSelect(PORTC_BASE_PTR, 16, PORT_PDD_PULL_UP);
	  PORT_PDD_SetPinPullEnable(PORTC_BASE_PTR, 16, PORT_PDD_PULL_ENABLE);
	  PORT_PDD_SetPinPullSelect(PORTC_BASE_PTR, 17, PORT_PDD_PULL_UP);
	  PORT_PDD_SetPinPullEnable(PORTC_BASE_PTR, 17, PORT_PDD_PULL_ENABLE);
#endif
  PL_Init();
#if PL_CONFIG_HAS_RTOS
  FRTOS1_vTaskStartScheduler();
#endif
}


