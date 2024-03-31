#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findMaxLength(std::vector<int>& nums) {
    int maxLength{0};

    int diff{0};
    std::unordered_map<int, int> posOfDiff{{0, -1}};

    for (int i{0}; i < static_cast<int>(nums.size()); ++i) {
      nums[i] == 0 ? --diff : ++diff;

      const auto it{posOfDiff.find(diff)};
      if (it != posOfDiff.end()) {
        maxLength = std::max(maxLength, i - it->second);
      } else {
        posOfDiff.emplace(diff, i);
      }
    }

    return maxLength;
  }
};
