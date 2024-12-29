#include <vector>

class Solution {
 public:
  int slidingPuzzle(std::vector<std::vector<int>>& board) {
    return board.front().front();
  }
};
