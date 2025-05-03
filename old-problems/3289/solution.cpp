#include <vector>

class Solution {
 public:
  std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
    std::vector<int> output{};
    output.reserve(2);

    for (const auto num : nums) {
      if (nums[num % 100] >= 100) {
        output.push_back(num % 100);
      } else {
        nums[num % 100] += 100;
      }
    }

    return output;
  }
};
