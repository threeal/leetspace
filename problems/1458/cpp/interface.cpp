#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(vector<int> nums1, vector<int> nums2) {
  return Solution().maxDotProduct(nums1, nums2);
}
