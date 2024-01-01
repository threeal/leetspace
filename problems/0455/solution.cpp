#include <algorithm>
#include <vector>

class Solution {
 public:
  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    const int n = std::min(g.size(), s.size());
    while (i < n) {
      if (g[i] > s[i]) break;
      ++i;
    }

    return i;
  }
};
