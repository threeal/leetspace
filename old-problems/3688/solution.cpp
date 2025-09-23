#include <vector>

class Solution {
 public:
  int evenNumberBitwiseORs(std::vector<int>& nums) {
    int sum{0};
    for (const int num : nums) {
      if (num % 2 == 0) sum |= num;
    }
    return sum;
  }
};
