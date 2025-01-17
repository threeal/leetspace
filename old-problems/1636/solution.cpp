#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> frequencySort(std::vector<int>& nums) {
    std::unordered_map<int, std::int8_t> frequencies{};
    for (const auto num : nums) {
      ++frequencies[num];
    }

    std::sort(nums.begin(), nums.end(), [&](const int a, const int b) {
      const auto freqa = frequencies[a];
      const auto freqb = frequencies[b];
      return freqa == freqb ? a > b : freqa < freqb;
    });

    return nums;
  }
};
