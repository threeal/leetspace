#include <vector>

class Solution {
 public:
  std::vector<long long> findXSum(std::vector<int>& nums, int k, int x) {
    return std::vector<long long>(nums.size() - k, x);
  }
};
