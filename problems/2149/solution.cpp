#include <vector>

class Solution {
 public:
  std::vector<int> rearrangeArray(std::vector<int>& nums) {
    std::vector<int> output(nums.size());

    std::size_t positive = 0;
    std::size_t negative = 1;
    for (const auto num : nums) {
      if (num >= 0) {
        output[positive] = num;
        positive += 2;
      } else {
        output[negative] = num;
        negative += 2;
      }
    }

    return output;
  }
};
