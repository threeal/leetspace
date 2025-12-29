#include <algorithm>
#include <vector>

class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    std::vector<std::tuple<int, int>> nums(hi + 1 - lo);
    for (int num{lo}; num <= hi; ++num) {
      int steps{0}, val{num};
      while (val != 1) {
        val = val % 2 == 0 ? val / 2 : val * 3 + 1;
        ++steps;
      }
      nums[num - lo] = {steps, num};
    }

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end());

    return std::get<1>(nums[k - 1]);
  }
};
