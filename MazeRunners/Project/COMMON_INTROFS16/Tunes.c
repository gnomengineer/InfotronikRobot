/*
 * Tunes.c
 *
 *  Created on: 24 Mar 2016
 *      Author: troopa
 */

#include "Tunes.h"

static const BUZ_Note Standard[] =
{ /* freq, ms */
    {500,100},
    {300,500},
    {100,200},
	{0,0},
};

static const BUZ_Note Tonleiter[] =
{
		{_C4, Quarter_Note},
		{_D4, Quarter_Note},
		{_E4, Quarter_Note},
		{_F4, Quarter_Note},
		{_G4, Quarter_Note},
		{_A4, Quarter_Note},
		{_B4, Quarter_Note},
		{0,0}
};

static const BUZ_Note Tetris[] =
{
		{_E4, Quarter_Note},
		{_B3, Eighth_Note},
		{_C4, Eighth_Note},
		{_D4, Quarter_Note},
		{_C4, Eighth_Note},
		{_B3, Eighth_Note},
		{_A3, Quarter_Note},
		{_A3, Eighth_Note},
		{_C4, Eighth_Note},
		{_E4, Quarter_Note},
		{_D4, Eighth_Note},
		{_C4, Eighth_Note},
		{_B3, Quarter_Note},
		{_B3, Eighth_Note},
		{_C4, Eighth_Note},
		{_D4, Quarter_Note},
		{_E4, Quarter_Note},
		{_C4, Quarter_Note},
		{_A3, Quarter_Note},
		{_A3, Quarter_Note},
		{_R, Quarter_Note},
		{_D4, Half_Note},
		{_F4, Eighth_Note},
		{_A4, Quarter_Note},
		{_G4, Eighth_Note},
		{_F4, Eighth_Note},
		{_E4, Half_Note},
		{_C4, Eighth_Note},
		{_E4, Quarter_Note},
		{_D4, Eighth_Note},
		{_C4, Eighth_Note},
		{_B3, Quarter_Note},
		{_B3, Eighth_Note},
		{_C4, Eighth_Note},
		{_D4, Quarter_Note},
		{_E4, Quarter_Note},
		{_C4, Quarter_Note},
		{_A3, Quarter_Note},
		{_A3, Quarter_Note},
		{_R, Quarter_Note},
		{0,0},
};

static const BUZ_Note Entlein[] = {
		{_D4, Eighth_Note},
		{_E4, Eighth_Note},
		{_F4, Eighth_Note},
		{_G4, Eighth_Note},
		{_A4, Quarter_Note},
		{_A4, Quarter_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_A4, Quarter_Note},
		{_R, Quarter_Note}, //pause
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_A4, Quarter_Note},
		{_R, Quarter_Note}, //pause
		{_G4, Eighth_Note},
		{_G4, Eighth_Note},
		{_G4, Eighth_Note},
		{_G4, Eighth_Note},
		{_F4, Quarter_Note},
		{_F4, Quarter_Note},
		{_A4, Eighth_Note},
		{_A4, Eighth_Note},
		{_A4, Eighth_Note},
		{_A4, Eighth_Note},
		{_D4, Quarter_Note},
		{0,0}
};

const BUZ_Note* Melody []=
{
	Standard,
	Tetris,
	Entlein,
	Tonleiter
};//*/

//const BUZ_Note** Melody = &Standard;


