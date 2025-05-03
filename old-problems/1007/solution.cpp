#include <vector>

class Solution {
 public:
  int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
    return tops.size() - bottoms.size();
  }
};
