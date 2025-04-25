#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, std::size_t> exists{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      auto it = exists.find(nums[i]);
      if (it == exists.end()) {
        exists.emplace(nums[i], i);
      } else {
        if (it->second + k >= i) return true;
        it->second = i;
      }
    }
    return false;
  }
};
