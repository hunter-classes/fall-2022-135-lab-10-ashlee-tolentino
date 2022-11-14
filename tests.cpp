#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "Time_class.h"

TEST_CASE("Length"){
  Coord3D point1 = {10, 20, 30};
  Coord3D point2 = {0, 48, 152};
  CHECK(length(&point1) == sqrt((10 * 10) + (20 * 20) + (30 * 30)));
  CHECK(length(&point2) == sqrt((0 * 0) + (48 * 48) + (152 * 152)));
}
