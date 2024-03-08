#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxFrequencyElements(std::vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }

    int maxCount = 0;
    int maxCountCount = 0;
    for (const auto [val, count] : counts) {
      if (count >= maxCount) {
        if (count > maxCount) {
          maxCount = count;
          maxCountCount = 1;
        } else {
          ++maxCountCount;
        }
      }
    }

    return maxCount * maxCountCount;
  }
};
