#include <vector>

class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    return triangle.front().front();
  }
};
