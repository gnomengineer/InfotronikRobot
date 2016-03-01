#include "Platform.h"
#include "Application.h"
#include "LED.h"

void APP_Start(void) {
  PL_Init();
  /* init: turn off */
  for(;;) {
    LED1_Neg();
    WAIT1_Waitms(500);
  }

  for(;;) {
    /* wait */
  }
}


