#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

TEST_CASE("4. Median of Two Sorted Arrays") {
  SECTION("Testcase 1") {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 2.0);
  }

  SECTION("Testcase 2") {
    Solution solution;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    CHECK(solution.findMedianSortedArrays(nums1, nums2) == 2.5);
  }
}
