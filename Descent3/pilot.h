/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.

--- HISTORICAL COMMENTS FOLLOW ---

 * $Logfile: /DescentIII/main/pilot.h $
 * $Revision: 47 $
 * $Date: 5/02/99 12:55a $
 * $Author: Jeff $
 *
 * Player/Pilot configuration
 *
 * $Log: /DescentIII/main/pilot.h $
 *
 * 47    5/02/99 12:55a Jeff
 * save ship permissions at highest level achieved and use that on restore
 * to a level previously played
 *
 * 46    3/23/99 12:45p Jeff
 * added preset control selection for pilot
 *
 * 45    3/22/99 6:22p Jeff
 * added 2 more audio taunts.  a mulitplayer event when someone plays an
 * audio taunt.  option to disable audio taunts.
 *
 * 44    3/15/99 9:25p Gwar
 *
 * 43    3/15/99 4:31p Jeff
 * fixed some memory leaks
 *
 * 42    2/27/99 4:18p Jeff
 * added support for .pld files (used to copy pilot default controls),
 * audio taunt size import error fixed...removed dead code
 *
 * 41    2/25/99 4:30p Jeff
 * mission data of pilot keeps track of all missions, not just after you
 * beat a level
 *
 * 40    2/20/99 3:44a Jeff
 * some more updates and bug fixes
 *
 * 39    2/15/99 7:50p Jeff
 * new pilot file class and read/write system checked in...should be more
 * robust than old
 *
 * 38    1/11/99 4:08p Jason
 * added multiplayer taunt macros
 *
 * 37    12/16/98 1:57p Samir
 * added finished field to mission data structure.
 *
 * 36    12/15/98 4:28p Jeff
 * added mission data information to the pilot files to save what the
 * highest level they achieved on a mission is.  Added level select dialog
 * (not hooked up) and level warp cheat.
 *
 * 35    12/03/98 11:06a Samir
 * added axis sensitivity
 *
 * 34    12/01/98 5:47p Jeff
 * created pilot picture selection dialog
 *
 * 33    11/30/98 11:57a Jeff
 * fixed bug, allowing unlimited pilots
 *
 * 32    10/22/98 2:58p Chris
 * Difficulty levels are in beta
 *
 * 31    10/21/98 11:54p Samir
 * fixed typos.
 *
 * 30    10/21/98 7:15p Samir
 * added joy and mouse sensitivities for pilot.
 *
 * 29    10/17/98 7:31p Samir
 * added invertible axes
 *
 * 28    10/15/98 1:36p Jeff
 * allow cancel out of pilot select menu
 *
 * 27    10/14/98 6:39p Samir
 * save screen size for game.
 *
 * 26    10/12/98 3:02p Jeff
 * added a verify function, give warning when they go into Multiplayer
 * ship customize with a bad ship
 *
 * 25    10/08/98 6:41p Jeff
 * when creating your first pilot it immediatly returns you to main menu
 *
 * 24    9/08/98 11:41a Jeff
 * new pilot selection interface
 *
 * 23    9/04/98 3:52p Jeff
 * changes made from UI meeting
 *
 * 22    9/04/98 1:20p Jeff
 * updates to ship selection, now includes audio taunts, strips crc's from
 * filenames when displaying
 *
 * 21    8/29/98 6:53p Jeff
 * added single-player ship selection
 *
 * 20    7/27/98 6:26p Jeff
 * basic implementation of ship configurations...needs to be purtied up
 *
 * 19    6/24/98 7:36p Samir
 * made pilot structure cleaner.
 *
 * 18    6/19/98 5:39p Samir
 * save out hud mode too.
 *
 * 17    6/19/98 3:30p Samir
 * added hud layout info in pilot file.
 *
 * 16    6/18/98 4:48p Samir
 * added changes for multiple configs for joystick controls.
 *
 * 15    6/17/98 3:28p Jeff
 * localization changes.  made an init function
 *
 * 14    5/24/98 2:56a Jeff
 * Pilot dialogs up to date
 *
 * 13    4/23/98 11:14p Samir
 * added read_controller flag to pilot.cpp
 *
 * 12    4/01/98 3:34p Jeff
 * ship_model is now a string
 *
 * 11    3/20/98 1:19p Jeff
 * Changes made to use Default_pilot string for pilot filename to use.
 *
 * 10    3/19/98 6:58p Jeff
 * Pilot stuff reads and writes to the correct directories
 *
 * 9     3/13/98 8:55p Jeff
 * Various changes to move control configuration into Pilot file
 *
 * 8     3/12/98 2:00p Jeff
 * Various changes to improve pilot dialogs
 *
 * 7     3/10/98 7:08p Jeff
 * Various changes due to new window class
 *
 * 6     3/10/98 11:57a Jeff
 * Corrected some function comments and made '.' a valid filename
 * character
 *
 * 5     3/10/98 11:50a Jeff
 * Added filename field to pilot structure, which keeps track of the pilot
 * filename...fixes any bugs that come with renaming a file.  Made changes
 * to take advantage of this.
 *
 * 4     3/09/98 6:27p Jeff
 * Cleaned up code, made file operations more robust, pretty sturdy now
 *
 * 3     3/06/98 6:32p Jeff
 * Added Pilot files and major functionality
 *
 * 2     3/05/98 4:28p Jeff
 * Initial creation
 *
 * $NoKeywords: $
 */

#ifndef __PILOT_H_
#define __PILOT_H_

#include <cstdlib>
#include <string>
#include <vector>

#include "pilot_class.h"

//	PilotSelect
//
//	Brings up a window where you can select a pilot to use
void PilotSelect();

// creates a new pilot (and pilot file)
// Returns: true on success
// Pilot: pointer to pilot structure to be filled in with name and filename (should then configure the rest)
bool PilotCreate(pilot *Pilot, bool dontallowcancel);

// Write a Pilot out to file
// Pilot - Pilot to write (filename field is root of filename extension .plt)
//			Make sure both filename and name are filled in before calling
// newpilot - Whether it is supposed to create a new file
//				false = overwrite existing file
//				true = don't overwrite any existing file, returns error if so
// Returns: PLT_FILE_*
int PltWriteFile(pilot *Pilot, bool newpilot = false);

// Reads a Pilot from file
// Pilot - pointer to structure to fill in...
//			MAKE SURE filename field is filled in with correct filename to read in before calling!!
// keyconfig - whether to set the controls on load
void PltReadFile(pilot *Pilot, bool keyconfig = false, bool missiondata = false);

// Given a string it will make a valid filename out of it
void PltMakeFNValid(char *name);

void PilotInit();

void PltClearList();
std::vector<std::string> PltGetPilots(std::string ignore_filename = {}, int display_default_configs = 0);

// VerifyPilotData
//
//	Call this function to check the data that is in the given pilot struct...it will verify that all files
//	listed are available, if they are not, then it will set them to defaults. Returns true if it had to
//	fix the data (you may want to save the pilot immediatly)
bool VerifyPilotData(pilot *Pilot);

// updates the current pilot's information (level played, mission played, etc)
//	call after every successful mission completion (by passing false)
//  call when a mission is loaded (pass true)
void CurrentPilotUpdateMissionStatus(bool just_add_data = false);

// gets highest level flown for mission
int PilotGetHighestLevelAchieved(pilot *Pilot, char *mission_name);
int GetPilotShipPermissions(pilot *Pilot, const char *mission_name);

extern pilot Current_pilot;
extern std::string Default_pilot;

// "Current Pilot" access functions
void dCurrentPilotName(char *buffer);

void IncrementPilotRestoredGamesForMission(pilot *Pilot, const char *mission_name);

#endif
