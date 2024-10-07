#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string largestNumber(std::vector<int>& nums) {
    std::vector<std::string> strs(nums.size());
    for (std::size_t i{0}; i < nums.size(); ++i) {
      strs[i] = std::to_string(nums[i]);
    }

    std::sort(
        strs.begin(), strs.end(),
        [](const std::string& a, const std::string& b) {
          return a + b > b + a;
        });

    std::string output{};
    for (const auto& str : strs) output += str;
    return output.front() == '0' ? "0" : output;
  }
};
