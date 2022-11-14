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
  
  return 0;
}
