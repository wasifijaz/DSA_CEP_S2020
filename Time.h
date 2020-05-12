#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int hour, min;
public:
	int time;
	Time();
	int getTime();
	string convertTime(int);
	int timeToGetAnswer(int);
};