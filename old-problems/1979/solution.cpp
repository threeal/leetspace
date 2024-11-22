#include <utility>
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

    while (smallest != 0) {
      std::swap(largest, smallest);
      smallest %= largest;
    }

    return largest;
  }
};
