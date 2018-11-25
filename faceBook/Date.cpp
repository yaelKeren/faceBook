#include "date.h"
#include <iostream>
#include <time.h>
using namespace std;

Date::Date()
{
	time_t cTime;
	struct tm* timeinfo;

	time(&cTime);
	timeinfo = localtime(&cTime);

	this->day = timeinfo->tm_yday;
	this->month = timeinfo->tm_mon + 1;
	this->year = timeinfo->tm_year;
	this->hours = timeinfo->tm_hour;
	this->minutes = timeinfo->tm_min;
}

//
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = 0;
	this->minutes = 0;
}
