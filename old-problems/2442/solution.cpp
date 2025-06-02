#include <algorithm>
#include <vector>

class Solution {
 public:
  int countDistinctIntegers(std::vector<int>& nums) {
    const std::size_t n{nums.size()};
    nums.reserve(n * 2);

    for (std::size_t i{0}; i < n; ++i) {
      int num{nums[i]}, rnum{0};
      while (num > 0) {
        rnum = rnum * 10 + num % 10;
        num /= 10;
      }
      nums.push_back(rnum);
    }

    std::sort(nums.begin(), nums.end());

    int count{1};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) ++count;
    }

    return count;
  }
};
