/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab10

This program works with classes, enums, and movies.
*/

#include <iostream>
#include <string>
#include "Time_class.h"
#include "Movie_class.h"
#include "TimeSlot_class.h"
#include "time.h"

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


// Helper functions for Time, Movie, and TimeSlot Classes
std::string printTime(Time time)
{
  std::string result = "";
  result = result + std::to_string(time.h) + ":" + std::to_string(time.m);
  return result;
}

std::string printMovie(Movie mv)
{
  std::string result = "";
  std::string g;
  switch (mv.genre)
  {
    case ACTION   : g = "ACTION"; break;
    case COMEDY   : g = "COMEDY"; break;
    case DRAMA    : g = "DRAMA";  break;
    case ROMANCE  : g = "ROMANCE"; break;
    case THRILLER : g = "THRILLER"; break;
  }
  result = result + mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
  return result;
}


/**
   Task C: This function prints out the movie title, genre, duration, the starting time, and the ending time.
 */
std::string getTimeSlot(TimeSlot ts)
{
  std::string str = "";
  str += printMovie(ts.movie);
  str += " [starts at ";
  str += printTime(ts.startTime);
  str += ", ends by ";
  Time result = addMinutes(ts.startTime, ts.movie.duration);
  str = str + std::to_string(result.h) + ":" + std::to_string(result.m) + "]\n";
  return str;
}

/**
   Task D: This function produces and returns a new TimeSlot for the movie nextMovie, scheduled immediately after the timeslot ts.
 */
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
  TimeSlot result;
  result.movie = nextMovie;
  result.startTime = addMinutes(ts.startTime, ts.movie.duration);
  return result;
}

/**
   Task E: This function returns true if the two time slots overlap, otherwise return false. (Take into account the starting times of the time slots and the duration of the scheduled movies.)
 */
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
  bool result = false;
  int start_time1_in_min = minutesSinceMidnight(ts1.startTime);
  int start_time2_in_min = minutesSinceMidnight(ts2.startTime);
  if(start_time1_in_min == start_time2_in_min)
  {
    result = true;
    return result;
  }
  else if(start_time1_in_min < start_time2_in_min)
  {
    if((start_time1_in_min + ts1.movie.duration) <= start_time2_in_min)
    {
      result = false;
      return result;
    }
    else
    {
      result = true;
      return result;
    }
  }
  else
  {
    if((start_time2_in_min + ts2.movie.duration) <= start_time1_in_min)
    {
      result = false;
      return result;
    }
    else
    {
      result = true;
      return result;
    }
  }

  return result;
}
