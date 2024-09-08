#include <vector>

class Solution {
 public:
  bool stoneGame(std::vector<int>& piles) {
    return piles.size() % 2 == 0;
  }
};
