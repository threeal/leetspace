#include <vector>

class Solution {
 public:
  int maximumXOR(std::vector<int>& nums) {
    int sum{0};
    for (const int num : nums) {
      sum |= num;
    }
    return sum;
  }
};
