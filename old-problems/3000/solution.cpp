#include <vector>

class Solution {
 public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
    return dimensions.front().front();
  }
};
