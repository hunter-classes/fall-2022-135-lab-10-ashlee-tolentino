/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab10

This program...
*/

#include <iostream>
#include <string>
#include "Time_class.h"
#include "Movie_class.h"
#include "TimeSlot_class.h"
#include "time.h"

int main()
{
  // Task A
  Time time1 = { 10, 30 };
  Time time2 = { 13, 40 };
  
  std::cout << "Task A\n\nThese moments of time are " << minutesSinceMidnight(time1) << " and " << minutesSinceMidnight(time2) << " minutes after midnight." << std::endl; // would print 630 and 820 minutes
  std::cout << "The interval between them is " << minutesUntil(time1, time2) << " minutes." << std::endl; // would print 190 minutes
  std::cout << "---------------------------------------\n";

  // Task B
  Time time3 = { 8, 10 };
  Time result = addMinutes(time3, 75);

  std::cout << "Task B\n\nThe new time is " << result.h << ":" << result.m << std::endl; // should return {9, 25}
  std::cout << "---------------------------------------\n";

  
  // Helper Functions for Time, Movie, and TimeSlot Classes
  //std::cout << "Helper Functions for Time, Movie, and TimeSlot Classes\n\n";
  //std::cout << "printTime\n";
  Time testTime = { 2, 30 };
  std::string resultTime = printTime(testTime);
  //std::cout << resultTime << std::endl;

  //std::cout << "\nprintMovie\n";
  Movie testMovie1 = {"Back to the Future", COMEDY, 116};
  Movie testMovie2 = {"Black Panther", ACTION, 134};
  std::string resultMovie = printMovie(testMovie1);
  //std::cout << resultMovie << std::endl;
  std::string resultMovie2 = printMovie(testMovie2);
  //std::cout << resultMovie2 << std::endl;
  

  // Task C
  std::cout << "Task C\n\n";
  TimeSlot morning = {testMovie1, {9, 15}};
  TimeSlot daytime = {testMovie2, {12, 15}}; 
  TimeSlot evening = {testMovie2, {16, 45}};
  std::string resultSlot = getTimeSlot(morning);
  std::cout << resultSlot;
  std::string resultSlot2 = getTimeSlot(daytime);
  std::cout << resultSlot2;
  std::string resultSlot3 = getTimeSlot(evening);
  std::cout << resultSlot3;
  std::cout << "---------------------------------------\n";
 
  // Task D
  std::cout << "Task D\n\n";
  std::cout << "Previous Movie TimeSlot:\n";
  Movie prevMov = {"The Little Mermaid", ROMANCE, 120};
  TimeSlot prevMovie = {prevMov, {14, 10}};
  std::string prevMovieSlot = getTimeSlot(prevMovie);
  std::cout << prevMovieSlot;

  std::cout << "\nNext Movie TimeSlot:\n";
  Movie nextMov = {"Cinderella", DRAMA, 120};
  TimeSlot nextMovie = scheduleAfter(prevMovie, nextMov);
  std::string nextMovieSlot = getTimeSlot(nextMovie);
  std::cout << nextMovieSlot;
  std::cout << "---------------------------------------\n";

  //Task E
  std::cout << "Task E\n\n";
  std::cout << "Movie 1\n";
  Movie m1 = {"Tangled", ACTION, 90};
  TimeSlot ts1 = {m1, {10, 00}};
  std::string first_ts = getTimeSlot(ts1);
  std::cout << first_ts;

  std::cout << "\nMovie 2\n";
  Movie m2 = {"Sleeping Beauty", DRAMA, 90};
  TimeSlot ts2 = {m2, {11, 30}};
  std::string second_ts = getTimeSlot(ts2);
  std::cout << second_ts;

  bool are_overlapping = timeOverlap(ts1, ts2);
  std::cout << "\nDo Movie 1 and Movie 2 overlap? (1 = true, 0 = false)\n" << are_overlapping << std::endl;
  
  return 0;
}
