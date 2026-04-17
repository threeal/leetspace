#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minMirrorPairDistance(std::vector<int>& nums) {
    std::size_t minDistance{nums.size()};
    std::unordered_map<int, std::size_t> mirrorIndices{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      int num{nums[i]};
      const auto it = mirrorIndices.find(num);
      if (it != mirrorIndices.end()) {
        if (i - it->second < minDistance) minDistance = i - it->second;
      }

      int mirror{0};
      while (num != 0) {
        mirror = mirror * 10 + num % 10;
        num /= 10;
      }

      auto mirrorIt = mirrorIndices.find(mirror);
      if (mirrorIt != mirrorIndices.end()) {
        mirrorIt->second = i;
      } else {
        mirrorIndices.emplace(mirror, i);
      }
    }
    return minDistance == nums.size() ? -1 : minDistance;
  }
};
