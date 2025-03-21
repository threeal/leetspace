#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
    int count{0}, left{0};
    for (int i{0}; i < colors.size() + k - 1; ++i) {
      while (left > 0 &&
      if (right - left + 1 >= k) ++count;
    }
    return count;
  }
};
