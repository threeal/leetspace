#include <numeric>
#include <vector>

class Solution {
 public:
  int countBeautifulPairs(std::vector<int>& nums) {
    int count{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      while (nums[i] > 9) nums[i] /= 10;
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        if (std::gcd(nums[i], nums[j] % 10) == 1) ++count;
      }
    }
    return count;
  }
};
