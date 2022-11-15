#include <iostream>
#include <string>
#include "Time_class.h"
#include "Movie_class.h"
#include "TimeSlot_class.h"

#pragma once

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
// Helper Functions
std::string printTime(Time time);
std::string printMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);
