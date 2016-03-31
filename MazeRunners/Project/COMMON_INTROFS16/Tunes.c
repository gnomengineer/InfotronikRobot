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
		{_E5, Quarter_Note},
		{_B4, Eighth_Note},
		{_C5, Eighth_Note},
		{_D5, Quarter_Note},
		{_C5, Eighth_Note},
		{_B4, Eighth_Note},
		{_A4, Quarter_Note},
		{_A4, Eighth_Note},
		{_C5, Eighth_Note},
		{_E5, Quarter_Note},
		{_D5, Eighth_Note},
		{_C5, Eighth_Note},
		{_B4, Quarter_Note},
		{_B4, Eighth_Note},
		{_C5, Eighth_Note},
		{_D5, Quarter_Note},
		{_E5, Quarter_Note},
		{_C5, Quarter_Note},
		{_A4, Quarter_Note},
		{_A4, Quarter_Note},
		{_R, Quarter_Note},
		{_D5, Half_Note},
		{_F5, Eighth_Note},
		{_A5, Quarter_Note},
		{_G5, Eighth_Note},
		{_F5, Eighth_Note},
		{_E5, Half_Note},
		{_C5, Eighth_Note},
		{_E5, Quarter_Note},
		{_D5, Eighth_Note},
		{_C5, Eighth_Note},
		{_B4, Quarter_Note},
		{_B4, Eighth_Note},
		{_C5, Eighth_Note},
		{_D5, Quarter_Note},
		{_E5, Quarter_Note},
		{_C5, Quarter_Note},
		{_A4, Quarter_Note},
		{_A4, Quarter_Note},
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

static const BUZ_Note GameOfThrones[] =
{
		//part 1
		{_G5, Quarter_Note_dot},
		{_C5, Quarter_Note_dot},
		{_C5, Sixth_Note},
		{_F5, Sixth_Note},
		{_G5, Quarter_Note},
		{_C5, Quarter_Note},
		{_C5, Sixth_Note},
		{_DS5, Sixth_Note},
		{_D5, Half_Note_dot},
		{_R ,Half_Note},
		//part 2
		{_F5, Quarter_Note_dot},
		{_AS4, Quarter_Note_dot},
		{_AS4, Sixth_Note},
		{_DS5, Sixth_Note},
		{_F5, Quarter_Note},
		{_AS4, Quarter_Note},
		{_DS5, Sixth_Note},
		{_D5, Sixth_Note},
		{_C5, Half_Note_dot},
		{_R ,Half_Note},

		{0,0}
};

static const BUZ_Note Mario[] =
{
		{_E5, Eighth_Note},
		{_E5, Eighth_Note},
		{_R, Eighth_Note},
		{_E5, Eighth_Note},
		{_R, Eighth_Note},
		{_C5, Eighth_Note},
		{_E5, Quarter_Note},

		{_G5, Quarter_Note},
		{_R, Quarter_Note},
		{_G4, Quarter_Note},
		{_R, Quarter_Note},

		{_C5, Quarter_Note_dot},
		{_G4, Eighth_Note},
		{_R, Quarter_Note},
		{_E4, Quarter_Note},

		{_E4, Eighth_Note},
		{_A4, Quarter_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_AS4, Eighth_Note},
		{_A4, Quarter_Note},

		{_G4, Triole},
		{_E5, Triole},
		{_G5, Triole},
		{_A5, Quarter_Note},
		{_F5, Eighth_Note},
		{_G5, Eighth_Note},

		{_R, Eighth_Note},
		{_E5, Quarter_Note},
		{_C5, Eighth_Note},
		{_D5, Eighth_Note},
		{_B4, Quarter_Note},
		{_R, Eighth_Note},

		{_C5, Quarter_Note_dot},
		{_G4, Eighth_Note},
		{_R, Quarter_Note},
		{_E4, Quarter_Note},

		{_E4, Eighth_Note},
		{_A4, Quarter_Note},
		{_B4, Eighth_Note},
		{_B4, Eighth_Note},
		{_AS4, Eighth_Note},
		{_A4, Quarter_Note},

		{_G4, Triole},
		{_E5, Triole},
		{_G5, Triole},
		{_A5, Quarter_Note},
		{_F5, Eighth_Note},
		{_G5, Eighth_Note},

		{_R, Eighth_Note},
		{_E5, Quarter_Note},
		{_C5, Eighth_Note},
		{_D5, Eighth_Note},
		{_B4, Quarter_Note},
		{_R, Eighth_Note},

		{0,0}
};

const BUZ_Note* Melody []=
{
	Standard,
	Tetris,
	Entlein,
	Tonleiter,
	GameOfThrones,
	Mario
};//*/

//const BUZ_Note** Melody = &Standard;


