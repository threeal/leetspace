#include <vector>

class Solution {
 public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    return piles.size() / h;
  }
};
