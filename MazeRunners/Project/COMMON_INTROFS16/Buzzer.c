/**
 * \file
 * \brief Buzzer driver interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for the buzzer.
 */

#include "Platform.h"
#if PL_CONFIG_HAS_BUZZER
#include "Buzzer.h"
#include "Tunes.h"
#include "BUZ1.h"
#include "Trigger.h"
#include "UTIL1.h"
#if PL_CONFIG_HAS_SHELL
  #include "CLS1.h"
#endif

typedef struct {
  uint16_t buzPeriodTicks; /*!< number of trigger ticks for a PWM period */
  uint16_t buzIterationCntr; /*!< number of iterations */
} BUZ_TrgInfo;

static volatile BUZ_TrgInfo trgInfo;

static void BUZ_Toggle(void *dataPtr) {
  BUZ_TrgInfo *trgInfo = (BUZ_TrgInfo *)dataPtr;
  
  if (trgInfo->buzIterationCntr==0) {
    BUZ1_ClrVal(); /* turn buzzer off */
  } else {
    trgInfo->buzIterationCntr--;
    BUZ1_NegVal();
    (void)TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo->buzPeriodTicks, BUZ_Toggle, trgInfo);
  }
}

uint8_t BUZ_Beep(uint16_t freq, uint16_t durationMs) {
  if (trgInfo.buzIterationCntr==0) { /* only if buzzer is not running right now */
    BUZ1_SetVal(); /* turn buzzer on */
    //trgInfo.buzPeriodTicks = (1000*TRG_TICKS_MS)/freq;
    trgInfo.buzPeriodTicks = (6000*TRG_TICKS_MS)/freq;
    trgInfo.buzIterationCntr = durationMs/TRG_TICKS_MS/trgInfo.buzPeriodTicks;
    return TRG_SetTrigger(TRG_BUZ_BEEP, trgInfo.buzPeriodTicks, BUZ_Toggle, (void*)&trgInfo);
  } else {
    return ERR_BUSY;
  }
}

//static const BUZ_Note Melody[] = ;

typedef struct{
	MELODIES melody;
	int currentNote;
} TUNEData;

static TUNEData start_note_melody = {STANDARD,0};

static void BUZ_Play(TUNEData *dataPtr) {
  int idx = dataPtr->currentNote;
  int melody = dataPtr->melody;

  int current_note_ms = Melody[melody][idx].ms;
  BUZ_Beep(Melody[melody][idx].freq, Melody[melody][idx].ms);
  dataPtr->currentNote = ++idx;
  if(Melody[melody][idx].ms != 0)
  {
	  TRG_SetTrigger(TRG_BUZ_TUNE, current_note_ms/TRG_TICKS_MS, (TRG_Callback)BUZ_Play, (void*)dataPtr);
  }
  /*
  if (idx<(sizeof(Melody[melody])/sizeof(Melody[melody][0]))) {
    TRG_SetTrigger(TRG_BUZ_TUNE, Melody[melody][idx-1].ms/TRG_TICKS_MS, (TRG_Callback)BUZ_Play, (void*)dataPtr);
  }//*/
}

uint8_t BUZ_PlayTune(MELODIES melody) {
  start_note_melody.melody = melody;
  start_note_melody.currentNote = 0;
  return TRG_SetTrigger(TRG_BUZ_TUNE, 1, (TRG_Callback)BUZ_Play, (void*)&start_note_melody);
}


#if PL_CONFIG_HAS_SHELL
static uint8_t BUZ_PrintHelp(const CLS1_StdIOType *io) {
  CLS1_SendHelpStr((unsigned char*)"buzzer", (unsigned char*)"Group of buzzer commands\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Shows radio help or status\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  buz <freq> <time>", (unsigned char*)"Beep for time (ms) and frequency (kHz)\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  play tune", (unsigned char*)"Play tune\r\n", io->stdOut);
  return ERR_OK;
}

static uint8_t BUZ_PrintStatus(const CLS1_StdIOType *io) {
  (void)io; /* not used */
  return ERR_OK;
}

uint8_t BUZ_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io) {
  const unsigned char *p;
  uint16_t freq, duration;

  if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, (char*)"buzzer help")==0) {
    *handled = TRUE;
    return BUZ_PrintHelp(io);
  } else if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_STATUS)==0 || UTIL1_strcmp((char*)cmd, (char*)"buzzer status")==0) {
    *handled = TRUE;
    return BUZ_PrintStatus(io);
  } else if (UTIL1_strncmp((char*)cmd, (char*)"buzzer buz ", sizeof("buzzer buz ")-1)==0) {
    *handled = TRUE;
    p = cmd+sizeof("buzzer buz ")-1;
    if (UTIL1_ScanDecimal16uNumber(&p, &freq)==ERR_OK && UTIL1_ScanDecimal16uNumber(&p, &duration)==ERR_OK) {
      if (BUZ_Beep(freq, duration)!=ERR_OK) {
        CLS1_SendStr((unsigned char*)"Starting buzzer failed\r\n", io->stdErr);
        return ERR_FAILED;
      }
      return ERR_OK;
    }
  } else if (UTIL1_strcmp((char*)cmd, (char*)"buzzer play tune")==0) {
    *handled = TRUE;
    if(tune == NOF_TUNES)
    {
    	tune = 0;
    }
    return BUZ_PlayTune(tune++);
  }
  return ERR_OK;
}
#endif /* PL_CONFIG_HAS_SHELL */

void BUZ_Deinit(void) {
  /* nothing to do */
}

void BUZ_Init(void) {
  BUZ1_SetVal(); /* turn buzzer off */
  static int8_t tune = 0;
  trgInfo.buzPeriodTicks = 0;
  trgInfo.buzIterationCntr = 0;
}
#endif /* PL_CONFIG_HAS_BUZZER */
