#include <vector>

class Solution {
 public:
  int maxTotalFruits(
      std::vector<std::vector<int>>& fruits, int startPos, int k) {
    return fruits[0][0] + startPos + k;
  }
};
