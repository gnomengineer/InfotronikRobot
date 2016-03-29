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

/*
#define _C3    (130.81)
#define _CS3   (138.59)
#define _D3    (146.83)
#define _DS3   (155.56)
#define _E3    (164.81)
#define _F3    (174.61)
#define _FS3   (185.00)
#define _G3    (196.00)
#define _GS3   (207.65)
#define _A3    (220.00)
#define _AS3   (233.08)
#define _B3    (246.94)
#define _C4    (261.63)
#define _CS4   (277.18)
#define _D4    (293.66)
#define _DS4   (311.13)
#define _E4    (329.63)
#define _F4    (349.23)
#define _FS4   (369.99)
#define _G4    (392.00)
#define _GS4   (415.30)
#define _A4    (440.00)
#define _AS4   (466.16)
#define _B4    (493.88)
#define _C5    (523.25)
#define _CS5   (554.37)
#define _D5    (587.33)
#define _DS5   (622.25)
#define _E5    (659.25)
#define _F5    (698.46)
#define _FS5   (739.99)
#define _G5    (783.99)
#define _GS5   (830.61)
#define _A5    (880.00)
#define _AS5   (932.33)
#define _B5    (987.77)

/* definition of length of the notes */
#define Half_Note	(1000)
#define Quarter_Note	(500)
#define Eighth_Note	(250)
#define Stop (100)

/* end definition of notes */

//enum for all available tunes
typedef enum
{
	STANDARD,
	TETRIS,
	ENTLEIN,
	TONLEITER,
	NOF_TUNES
} MELODIES;

typedef struct {
  int freq; /* frequency */
  int ms; /* milliseconds */
} BUZ_Note;

extern const BUZ_Note* Melody[];
//extern const BUZ_Note** Melody;



#endif /* SOURCES_COMMON_INTROFS16_TUNES_H_ */
