/*
 * Platform.h
 *
 *  Created on: 1 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_PLATFORM_H_
#define SOURCES_COMMON_INTROFS16_PLATFORM_H_

#include "Platform_Local.h"
#include "Cpu.h"
#include <stdint.h>
#include <stdbool.h>

#if defined(PEcfg_RoboV2)
	#define PL_CONFIG_IS_ROBO_V2 (1)
#else
	#define PL_CONFIG_IS_ROBO_V2 (0)
#endif

#define PL_CONFIG_IS_ROBO PL_LOCAL_IS_ROBO
#define PL_CONFIG_IS_FRDM PL_LOCAL_IS_FRDM

#define PL_CONFIG_NOF_LED 		PL_LOCAL_NOF_LED
#define PL_CONFIG_NOF_KEYS		PL_LOCAL_NOF_KEY


#define PL_CONFIG_HAS_EVENTS 	(1 && defined(PL_LOCAL_HAS_EVENTS))
#define PL_CONFIG_HAS_TIMER		(1 && defined(PL_LOCAL_HAS_TIMER))
#define PL_CONFIG_HAS_LED 		(1 && defined(PL_LOCAL_HAS_LED))
#define PL_CONFIG_HAS_KEY 		(1 && defined(PL_LOCAL_HAS_KEY))
#define PL_CONFIG_HAS_JOYSTICK	(1 && defined(PL_LOCAL_HAS_JOYSTICK))
#define PL_CONFIG_HAS_TRIGGER	(1 && defined(PL_LOCAL_HAS_TRIGGER))
#define PL_CONFIG_HAS_BUZZER	(1 && defined(PL_LOCAL_HAS_BUZZER))
#define PL_CONFIG_HAS_SHELL		(1 && defined(PL_LOCAL_HAS_SHELL))
#define PL_CONFIG_HAS_DEBOUNCE	(1 && defined(PL_LOCAL_HAS_DEBOUNCE))
#define PL_CONFIG_HAS_RTOS		(1 && defined(PL_LOCAL_HAS_RTOS))

#define PL_CONFIG_HAS_SEGGER_RTT        (0 && PL_CONFIG_HAS_SHELL) /* using RTT with shell */
#define PL_CONFIG_HAS_SHELL_QUEUE       (1 && PL_CONFIG_HAS_SHELL) /* enable shell queueing */
#define PL_CONFIG_SQUEUE_SINGLE_CHAR    (0 && PL_CONFIG_HAS_SHELL_QUEUE) /* using single character shell queue */
#define PL_CONFIG_HAS_SEMAPHORE         (0) /* semaphore tests */
#define PL_CONFIG_HAS_REFLECTANCE       (1 && PL_CONFIG_IS_ROBO)

#define PL_CONFIG_HAS_BLUETOOTH         (0 && defined(PL_LOCAL_HAS_BLUETOOTH))
#define PL_CONFIG_HAS_MOTOR             (1 && defined(PL_LOCAL_HAS_MOTOR))
#define PL_CONFIG_HAS_MCP4728           (0)
#define PL_CONFIG_HAS_QUADRATURE        (1 && defined(PL_LOCAL_HAS_QUADRATURE))
#define PL_CONFIG_HAS_QUAD_CALIBRATION  (0)
#define PL_CONFIG_HAS_MOTOR_TACHO       (1 && PL_CONFIG_HAS_QUADRATURE)
#define PL_CONFIG_HAS_PID               (1 && PL_CONFIG_HAS_MOTOR)
#define PL_CONFIG_HAS_DRIVE             (1 && PL_CONFIG_HAS_MOTOR)
#define PL_CONFIG_HAS_TURN              (1 && PL_CONFIG_HAS_MOTOR)
#define PL_CONFIG_HAS_LINE_FOLLOW       (1 && PL_CONFIG_HAS_REFLECTANCE)
#define PL_CONFIG_HAS_RADIO             (1)
#define RNET_CONFIG_REMOTE_STDIO        (1) /* temporary only, to be remove when RNET gets added */
#define PL_CONFIG_HAS_REMOTE            (1)
#define PL_CONFIG_CONTROL_SENDER		(1 && PL_CONFIG_IS_FRDM)
#define PL_CONFIG_HAS_LINE_MAZE         (0)

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_INTROFS16_PLATFORM_H_ */
