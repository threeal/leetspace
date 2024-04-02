#include <algorithm>
#include <vector>

class Solution {
 public:
  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    auto gi = g.begin();
    auto si = s.begin();
    while (gi != g.end() && si != s.end()) {
      if (*gi <= *si) ++gi;
      ++si;
    }

    return std::distance(g.begin(), gi);
  }
};
