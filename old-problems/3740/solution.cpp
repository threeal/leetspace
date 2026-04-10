#include <vector>

class Solution {
 public:
  int minimumDistance(std::vector<int>& nums) {
    std::size_t minDist{nums.size() * 3};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) {
          for (std::size_t k{j + 1}; k < nums.size(); ++k) {
            if (nums[j] == nums[k]) {
              const std::size_t dist{2 * (k - i)};
              if (dist < minDist) minDist = dist;
            }
          }
        }
      }
    }
    return minDist == nums.size() * 3 ? -1 : minDist;
  }
};
