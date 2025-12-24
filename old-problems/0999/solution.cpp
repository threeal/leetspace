#include <vector>

class Solution {
 public:
  int numRookCaptures(std::vector<std::vector<char>>& board) {
    return board.front().size();
  }
};
