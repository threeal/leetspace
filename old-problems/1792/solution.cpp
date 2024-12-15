#include <vector>

class Solution {
 public:
  double maxAverageRatio(
      std::vector<std::vector<int>>& classes, int extraStudents) {
    return classes.size() * extraStudents;
  }
};
