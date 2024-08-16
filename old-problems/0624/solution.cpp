#include <vector>

class Solution {
 public:
  int maxDistance(std::vector<std::vector<int>>& arrays) {
    int min{10000}, max{-10000};
    for (const auto& array : arrays) {
      if (array.front() < min) min = array.front();
      if (array.back() > max) max = array.back();
    }
    return max - min;
  }
};
