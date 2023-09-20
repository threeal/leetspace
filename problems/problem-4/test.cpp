#include <stack>
#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

TEST_CASE("4. Median of Two Sorted Arrays") {
  SECTION("Odd total size") {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 2.0);
  }

  SECTION("Even total size") {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 2.5);
  }

  SECTION("Empty first array odd total size") {
    Solution solution;
    vector<int> nums1 = {};
    vector<int> nums2 = {2, 3, 6};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 3.0);
  }

  SECTION("Empty first array even total size") {
    Solution solution;
    vector<int> nums1 = {};
    vector<int> nums2 = {2, 3, 6, 7};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 4.5);
  }

  SECTION("Empty second array odd total size") {
    Solution solution;
    vector<int> nums1 = {2, 3, 6};
    vector<int> nums2 = {};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 3.0);
  }

  SECTION("Empty second array even total size") {
    Solution solution;
    vector<int> nums1 = {2, 3, 6, 7};
    vector<int> nums2 = {};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 4.5);
  }
}
