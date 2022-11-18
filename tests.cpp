#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "Time_class.h"
#include "Movie_class.h"
#include "TimeSlot_class.h"
#include <string>

TEST_CASE("Minutes Since Midnight"){
  Time time1 = { 10, 30 };
  Time time2 = { 13, 40 };
  Time time3 = { 6, 00 };
  Time time4 = { 23, 01 };
  CHECK(minutesSinceMidnight(time1) == 630);
  CHECK(minutesSinceMidnight(time2) == 820);
  CHECK(minutesSinceMidnight(time3) == 360);
  CHECK(minutesSinceMidnight(time4) == 1381);
}

TEST_CASE("Minutes Until"){
  Time time1 = { 10, 30 };
  Time time2 = { 13, 40 };
  CHECK(minutesUntil(time1, time2) == 190);
  CHECK(minutesUntil(time2, time1) == -190);
  CHECK(minutesUntil(time2, time2) == 0);
}

TEST_CASE("Add Minutes"){
  Time time1 = { 8, 10 };
  Time result = addMinutes(time1, 75);
  CHECK(result.h == 9);
  CHECK(result.m == 25);
}

TEST_CASE("Get TimeSlot"){
  Movie testMovie1 = {"Back to the Future", COMEDY, 116};
  Movie testMovie2 = {"Black Panther", ACTION, 134};
  TimeSlot morning = {testMovie1, {9, 15}};
  TimeSlot daytime = {testMovie2, {12, 15}}; 
  TimeSlot evening = {testMovie2, {16, 45}};
  CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]\n");
  CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]\n");
  CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]\n");
}

TEST_CASE("Schedule After"){
  Movie prevMov = {"The Little Mermaid", ROMANCE, 120};
  TimeSlot prevMovie = {prevMov, {14, 10}};
  std::string prevMovieSlot = getTimeSlot(prevMovie);
  Movie nextMov = {"Cinderella", DRAMA, 120};
  TimeSlot nextMovie = scheduleAfter(prevMovie, nextMov);
  std::string nextMovieSlot = getTimeSlot(nextMovie);
  CHECK(prevMovieSlot == "The Little Mermaid ROMANCE (120 min) [starts at 14:10, ends by 16:10]\n");
  CHECK(nextMovieSlot == "Cinderella DRAMA (120 min) [starts at 16:10, ends by 18:10]\n");
}

TEST_CASE("Time Overlap"){
  Movie m1 = {"Tangled", ACTION, 90};
  TimeSlot ts1 = {m1, {10, 00}};
  Movie m2 = {"Sleeping Beauty", DRAMA, 90};
  TimeSlot ts2 = {m2, {11, 30}};
  TimeSlot ts3 = {m2, {11, 29}};
  CHECK(timeOverlap(ts1, ts2) == 0);
  CHECK(timeOverlap(ts2, ts1) == 0);
  CHECK(timeOverlap(ts1, ts3) == 1);
}
