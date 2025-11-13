#include <vector>

class Solution {
 public:
  int magicalSum(int m, int k, std::vector<int>& nums) {
    return m + k + nums.size();
  }
};
