#pragma once
#include <iostream>
#include <stack>
#include "Time.h"
//#include <fstream>

Time tm;
stack <int> lap;

int issueLaptop()
{
	int serial = lap.top();
	lap.pop();
	return serial;
}

int timeToGetLaptop(int m)
{
	int time = m + 2;
	return time;
}
//int issueLaptop();
//void getLaptops(ifstream&, int);