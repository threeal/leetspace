// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("3484. Design Spreadsheet") {
  SECTION("Example 1") {
    Spreadsheet spreadsheet(3);
    REQUIRE(spreadsheet.getValue("=5+7") == 12);
    spreadsheet.setCell("A1", 10);
    REQUIRE(spreadsheet.getValue("=A1+6") == 16);
    spreadsheet.setCell("B2", 15);
    REQUIRE(spreadsheet.getValue("=A1+B2") == 25);
    spreadsheet.resetCell("A1");
    REQUIRE(spreadsheet.getValue("=A1+B2") == 15);
  }
}
