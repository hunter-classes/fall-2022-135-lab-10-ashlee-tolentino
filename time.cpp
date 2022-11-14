/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab10

This program...
*/

#include <iostream>
#include "Time_class.h"
#include "time.h"

/*
class Time { 
public:
    int h;
    int m;
};
*/

/**
   Task A: The first function returns the number of minutes from 0:00AM until time. The second function receives two Time arguments earlier and later and reports how many minutes separate the two moments.
 */
int minutesSinceMidnight(Time time)
{
  int result = 0;
  result = (time.h * 60) + time.m;
  return result;
}

int minutesUntil(Time earlier, Time later)
{
  int result = 0;
  result = ((later.h - earlier.h) * 60) + (later.m - earlier.m);
  return result;
}

