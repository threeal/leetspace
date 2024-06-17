#include <vector>

class Solution {
 public:
  int addRungs(std::vector<int>& rungs, int dist) {
    int extraRungs{(rungs[0] - 1) / dist};
    for (std::size_t i{rungs.size() - 1}; i > 0; --i) {
      extraRungs += (rungs[i] - rungs[i - 1] - 1) / dist;
    }
    return extraRungs;
  }
};
