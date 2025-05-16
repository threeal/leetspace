#include <string>
#include <vector>

class Solution {
 public:
  int finalPositionOfSnake(int n, std::vector<std::string>& commands) {
    return n + commands.size();
  }
};
