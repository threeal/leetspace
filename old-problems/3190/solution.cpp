#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums) {
    int count{0};
    for (const int num : nums) {
      if (num % 3 != 0) ++count;
    }
    return count;
  }
};
