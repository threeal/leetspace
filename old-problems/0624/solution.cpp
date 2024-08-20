#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxDistance(std::vector<std::vector<int>>& arrays) {
    int distance{0};

    int prevMin{10001};
    int prevMax{-10001};

    for (const auto& array : arrays) {
      if (prevMax - array.front() > distance) {
        distance = prevMax - array.front();
      }

      if (array.back() - prevMin > distance) {
        distance = array.back() - prevMin;
      }

      if (array.front() < prevMin) prevMin = array.front();
      if (array.back() > prevMax) prevMax = array.back();
    }

    return distance;
  }
};
