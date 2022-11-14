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

/**
   Task B: This function creates and returns a new moment of time that is min minutes after time0.
 */
Time addMinutes(Time time0, int min)
{
  Time result;
  int hour = time0.h;
  int minutes = time0.m;

  
  if(time0.m + min < 60)
  {
    minutes = time0.m + min;
  }
  else if(time0.m + min == 60)
  {
    minutes = 0;
    hour++;
  }
  else
  {
    hour = hour + ((time0.m + min) / 60);
    minutes = (time0.m + min) % 60;
  }
  
  result.h = hour;
  result.m = minutes;
  return result;
}
