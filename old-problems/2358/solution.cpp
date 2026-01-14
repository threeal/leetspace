#include <cmath>
#include <vector>

class Solution {
 public:
  int maximumGroups(std::vector<int>& grades) {
    return std::sqrt(grades.size() * 2 + 0.25) - 0.5;
  }
};
