#include <vector>

class Solution {
 public:
  std::vector<int> stableMountains(std::vector<int>& height, int threshold) {
    height.pop_back();
    std::size_t n{0};
    for (std::size_t i{0}; i < height.size(); ++i) {
      if (height[i] > threshold) height[n++] = i + 1;
    }
    height.resize(n);
    return height;
  }
};
