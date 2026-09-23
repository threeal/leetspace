#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maximumLength(std::vector<int>& nums) {
    std::unordered_map<int, int> freqs{};
    for (int num : nums) {
      ++freqs[num];
    }

    int maxLen{1};
    for (const auto& [num, freq] : freqs) {
    }

    return maxLen;
  }
};
