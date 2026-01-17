#include <vector>

class Solution {
 public:
  long long largestSquareArea(
      std::vector<std::vector<int>>& bottomLeft,
      std::vector<std::vector<int>>& topRight) {
    return bottomLeft.size() + topRight.size();
  }
};
