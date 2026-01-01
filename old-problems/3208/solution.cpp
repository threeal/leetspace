#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
    int count{0}, l{0}, n = colors.size();
    for (int r{1}; r < n; ++r) {
      if (colors[r] != colors[r - 1]) {
        if (r + 1 - l >= k) ++count;
      } else {
        l = r;
      }
    }

    if (colors[0] != colors[colors.size() - 1]) {
      if (1 + n - l >= k) ++count;
      for (int r{1}; r + 1 < k; ++r) {
        if (colors[r] != colors[r - 1]) {
          if (r + 1 + n - l >= k) ++count;
        } else {
          break;
        }
      }
    }

    return count;
  }
};
