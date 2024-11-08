#include <vector>

class Solution {
 public:
  int robotSim(
      std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
    return commands.size() + obstacles.size();
  }
};
