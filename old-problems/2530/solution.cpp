#include <vector>

class Solution {
 public:
  long long maxKelements(std::vector<int>& nums, int k) {
    return nums.front() * k;
  }
};
