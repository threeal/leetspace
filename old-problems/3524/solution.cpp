#include <vector>

class Solution {
 public:
  std::vector<long long> resultArray(std::vector<int>& nums, int k) {
    return std::vector<long long>(k, static_cast<long long>(nums.size()));
  }
};
