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
#if PL_CONFIG_HAS_LINE_MAZE
	#include "Maze.h"
#endif
#if PL_CONFIG_HAS_REMOTE
	#include "RApp.h"
	#include "Remote.h"
#endif

#if PL_CONFIG_IS_ROBO_V2
	#include "PORT_PDD.h"
#endif
static int tune_counter = 0;

 void APP_HandleEvent(EVNT_Handle event)
  {
	int buf;
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
#if PL_CONFIG_HAS_LINE_MAZE
		MAZE_ClearSolution();
		MAZE_SetSolveAlgorithm(LEFT_HAND);
		LF_StartStopFollowing();
#endif
#if PL_CONFIG_HAS_SHELL
		//CLS1_SendStr("SW1_Pressed\n\r", CLS1_GetStdio()->stdOut);
		SHELL_SendString("SW1 Pressed\n\r");
		buf = 'A';
		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
#endif
  		break;

#if PL_CONFIG_IS_FRDM
  	case EVENT_SW2_PRESSED:
  	  	LED1_Neg();
  		buf = 'B';
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
  	  	break;
  	case EVENT_SW3_PRESSED:
  		buf = 'C';
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
  		break;
  	case EVENT_SW4_PRESSED:
  		buf = 'D';
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
  		break;
  	case EVENT_SW5_PRESSED:
  		buf = 'E';
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
  		break;
  	case EVENT_SW6_PRESSED:
  		buf = 'F';
  		REMOTE_SetOnOff(!REMOTE_GetOnOff());
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
  		break;
  	case EVENT_SW7_PRESSED:
  		buf = 'G';
  		(void)RAPP_SendPayloadDataBlock(&buf,sizeof(buf),RAPP_MSG_TYPE_JOYSTICK_BTN,RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
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


