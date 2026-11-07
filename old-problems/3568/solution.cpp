#include <string>
#include <vector>

class Solution {
 public:
  int minMoves(std::vector<std::string>& classroom, int energy) {
    return static_cast<int>(classroom.size()) + energy;
  }
};
