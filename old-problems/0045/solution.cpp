#include <algorithm>
#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    std::size_t near{0}, far{0};
    int jumpCount{0};

    while (far < nums.size() - 1) {
      std::size_t farthest{0};
      for (std::size_t i{near}; i <= far; ++i) {
        farthest = std::max(farthest, i + nums[i]);
      }

      near = far + 1;
      far = farthest;
      ++jumpCount;
    }

    return jumpCount;
  }
};
