#include <string>
#include <vector>

class Solution {
 public:
  std::string tictactoe(std::vector<std::vector<int>>& moves) {
    return moves.size() % 2 == 0 ? "A" : "B";
  }
};
