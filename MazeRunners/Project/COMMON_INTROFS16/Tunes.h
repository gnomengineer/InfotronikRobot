/*
 * Tunes.h
 *
 *  Created on: 24 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_TUNES_H_
#define SOURCES_COMMON_INTROFS16_TUNES_H_

#include "Buzzer.h"

/* start definition of notes here */


/* end definition of notes */

//enum for all available tunes
typedef enum
{
	STANDARD,
	TETRIS,
	NOF_TUNES
} MELODIES;

typedef struct {
  int freq; /* frequency */
  int ms; /* milliseconds */
} BUZ_Note;

static const BUZ_Note Standard[] =
{ /* freq, ms */
    {500,100},
    {300,500},
    {100,200},
};

static const BUZ_Note Tetris[] =

#endif /* SOURCES_COMMON_INTROFS16_TUNES_H_ */
