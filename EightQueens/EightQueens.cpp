// EightQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Memort leak stuff
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#define BRUTE 1
#define STATE 0

int main(int argc, char *argv[])
{
	int type = STATE;
	int size = DEFAULT_BOARD_SIZE;

	for (int i = 0; i < argc; i++) {
		if(strcmp(argv[i], "-t") == 0)
			if (strcmp(argv[i + 1], "brute") == 0)
				type = BRUTE;

		if (strcmp(argv[i], "-s") == 0)
			sscanf_s(argv[i+1], "%d", &size);
	}

	Engine *engine = new Engine();
	engine->setDimension(size);

	printf("Looking for a solution to the [%d] queens problem.\n",
		engine->getDimension());

	time_t start, end;

	time(&start);
	if (type == STATE)
		engine->stateFind();
	if (type == BRUTE)
		engine->bruteFind();
	time(&end);

	engine->print();

	printf("Took [%.0f] seconds to calulate [%d] results \n", 
		difftime(end, start), engine->results());

	delete engine;

	//system("pause");
	//int *pi = new int(10);
	_CrtDumpMemoryLeaks();
	return 0;
}
