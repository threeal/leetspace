#include <stack>
#include <string>
#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

struct TestCase {
  string title;
  vector<int> nums1;
  vector<int> nums2;
  double expected;
};

TEST_CASE("4. Median of Two Sorted Arrays") {
  Solution solution;

  auto [title, nums1, nums2, expected] = GENERATE(
      TestCase{
          .title = "Odd total size",
          .nums1 = {1, 3},
          .nums2 = {2},
          .expected = 2.0},
      TestCase{
          .title = "Even total size",
          .nums1 = {1, 3},
          .nums2 = {2, 4},
          .expected = 2.5},
      TestCase{
          .title = "Lower first array odd total size",
          .nums1 = {1},
          .nums2 = {2, 3},
          .expected = 2.0},
      TestCase{
          .title = "Lower first array even total size",
          .nums1 = {1, 2},
          .nums2 = {3, 4},
          .expected = 2.5},
      TestCase{
          .title = "Lower second array odd total size",
          .nums1 = {2, 3},
          .nums2 = {1},
          .expected = 2.0},
      TestCase{
          .title = "Lower second array even total size",
          .nums1 = {3, 4},
          .nums2 = {1, 2},
          .expected = 2.5},
      TestCase{
          .title = "Empty first array odd total size",
          .nums1 = {},
          .nums2 = {2, 3, 6},
          .expected = 3.0},
      TestCase{
          .title = "Empty first array even total size",
          .nums1 = {},
          .nums2 = {2, 3, 6, 7},
          .expected = 4.5},
      TestCase{
          .title = "Empty second array odd total size",
          .nums1 = {2, 3, 6},
          .nums2 = {},
          .expected = 3.0},
      TestCase{
          .title = "Empty second array even total size",
          .nums1 = {2, 3, 6, 7},
          .nums2 = {},
          .expected = 4.5});

  INFO(title);
  CHECK(solution.findMedianSortedArrays(nums1, nums2) == expected);
}
