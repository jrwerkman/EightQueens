// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <time.h>


// TODO: reference additional headers your program requires here
#include <iostream>
#include "Grid.h"
#include "State.h"
#include "Coords.h"
#include "GridList.h"
#include "EngineState.h"
#include "EngineBrute.h"
#include "Engine.h"
#include "Results.h"


#define DEFAULT_BOARD_SIZE 8

#define QUEEN 81
#define UNAVAILABLE 240
#define AVAILABLE 167
#define NOT_POSSIBLE 254
