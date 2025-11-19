// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1396. Design Underground System") {
  SECTION("Example 1") {
    UndergroundSystem sys{};
    sys.checkIn(45, "Leyton", 3);
    sys.checkIn(32, "Paradise", 8);
    sys.checkIn(27, "Leyton", 10);
    sys.checkOut(45, "Waterloo", 15);
    sys.checkOut(27, "Waterloo", 20);
    sys.checkOut(32, "Cambridge", 22);
    REQUIRE(sys.getAverageTime("Paradise", "Cambridge") == 14.00000);
    REQUIRE(sys.getAverageTime("Leyton", "Waterloo") == 11.00000);
    sys.checkIn(10, "Leyton", 24);
    REQUIRE(sys.getAverageTime("Leyton", "Waterloo") == 11.00000);
    sys.checkOut(10, "Waterloo", 38);
    REQUIRE(sys.getAverageTime("Leyton", "Waterloo") == 12.00000);
  }

  SECTION("Example 2") {
    UndergroundSystem sys{};
    sys.checkIn(10, "Leyton", 3);
    sys.checkOut(10, "Paradise", 8);
    REQUIRE(sys.getAverageTime("Leyton", "Paradise") == 5.00000);
    sys.checkIn(5, "Leyton", 10);
    sys.checkOut(5, "Paradise", 16);
    REQUIRE(sys.getAverageTime("Leyton", "Paradise") == 5.50000);
    sys.checkIn(2, "Leyton", 21);
    sys.checkOut(2, "Paradise", 30);
    REQUIRE(sys.getAverageTime("Leyton", "Paradise") == 6.66667);
  }
}
