#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int k) {
    int sum{0};
    for (const int num : nums) sum += num;
    return sum % k;
  }
};
