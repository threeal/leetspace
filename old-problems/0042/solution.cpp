#include <vector>

class Solution {
 public:
  int trap(std::vector<int>& height) {
    int volume{0};
    std::size_t l{0}, r{height.size() - 1};
    while (l + 1 < r) {
      if (height[l] <= height[r]) {
        if (height[l] > height[l + 1]) {
          volume += height[l] - height[l + 1];
          height[l + 1] = height[l];
        }
        ++l;
      } else {
        if (height[r] > height[r - 1]) {
          volume += height[r] - height[r - 1];
          height[r - 1] = height[r];
        }
        --r;
      }
    }
    return volume;
  }
};
