#include <vector>

class Solution {
 public:
  int findGCD(std::vector<int>& nums) {
    int smallest = nums[0];
    int largest = nums[0];
    for (std::size_t i = nums.size() - 1; i > 0; --i) {
      if (smallest > nums[i]) smallest = nums[i];
      if (largest < nums[i]) largest = nums[i];
    }

    for (int i = smallest; i > 0; --i) {
      if (smallest % i == 0 && largest % i == 0) return i;
    }

    return 1;
  }
};
