/*
 * Tunes.h
 *
 *  Created on: 24 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_TUNES_H_
#define SOURCES_COMMON_INTROFS16_TUNES_H_

/* start definition of notes here */
#define _R     (0)

#define _C3    (130)
#define _CS3   (138)
#define _D3    (146)
#define _DS3   (155)
#define _E3    (164)
#define _F3    (174)
#define _FS3   (185)
#define _G3    (196)
#define _GS3   (207)
#define _A3    (220)
#define _AS3   (233)
#define _B3    (246)
//Grundton C
#define _C4    (261)
#define _CS4   (277)
#define _D4    (293)
#define _DS4   (311)
#define _E4    (329)
#define _F4    (349)
#define _FS4   (369)
#define _G4    (392)
#define _GS4   (415)
#define _A4    (440)
#define _AS4   (466)
#define _B4    (493)
#define _C5    (523)
#define _CS5   (554)
#define _D5    (587)
#define _DS5   (622)
#define _E5    (659)
#define _F5    (698)
#define _FS5   (739)
#define _G5    (783)
#define _GS5   (830)
#define _A5    (880)
#define _AS5   (932)
#define _B5    (987)

/* definition of length of the notes */
#define Half_Note	(1000)
#define Quarter_Note	(500)
#define Triole (333)
#define Eighth_Note	(250)
#define Sixth_Note (125)
/* dotted notes */
#define Half_Note_dot (1500)
#define Quarter_Note_dot (750)
#define Eighth_Note_dot (375)

/* short break */
#define Stop (100)

/* end definition of notes */

//enum for all available tunes
typedef enum
{
	STANDARD,
	TETRIS,
	ENTLEIN,
	TONLEITER,
	GAMEOFTHRONE,
	MARIO,
	NOF_TUNES
} MELODIES;

typedef struct {
  int freq; /* frequency */
  int ms; /* milliseconds */
} BUZ_Note;

extern const BUZ_Note* Melody[];
//extern const BUZ_Note** Melody;



#endif /* SOURCES_COMMON_INTROFS16_TUNES_H_ */
