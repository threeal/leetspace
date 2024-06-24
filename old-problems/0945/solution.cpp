#include <algorithm>
#include <vector>

class Solution {
 public:
  int minIncrementForUnique(std::vector<int>& nums) {
    std::ranges::sort(nums);

    int moves{0};
    int minAvailable{0};
    for (const auto num : nums) {
      if (minAvailable > num) {
        moves += minAvailable - num;
        ++minAvailable;
      } else {
        minAvailable = num + 1;
      }
    }

    return moves;
  }
};
