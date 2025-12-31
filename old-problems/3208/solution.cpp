#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
    return colors.size() - k;
  }
};
