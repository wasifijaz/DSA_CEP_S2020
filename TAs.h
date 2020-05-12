#pragma once
#include "Students.h"

class TAs {
//private:
public:
	string name; 
	int startTimes[3];
	int endTimes[3];
	Students studentWithTA;
	int minute;
	TAs availableTA(TAs*, int, int);
};