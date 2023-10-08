#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const vector<int>& nums1, const vector<int>& nums2) {
  auto nums1_copy = nums1;
  auto nums2_copy = nums2;
  return Solution().maxDotProduct(nums1_copy, nums2_copy);
}
