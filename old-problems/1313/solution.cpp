#include <vector>

class Solution {
 public:
  std::vector<int> decompressRLElist(std::vector<int>& nums) {
    std::vector<int> output{};
    for (std::size_t i{1}; i < nums.size(); i += 2) {
      output.resize(output.size() + nums[i - 1], nums[i]);
    }
    return output;
  }
};
