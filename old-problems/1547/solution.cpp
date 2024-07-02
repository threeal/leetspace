#include <vector>

class Solution {
 public:
  int minCost(int n, std::vector<int>& cuts) {
    if (cuts.size() == 1) return n;

    std::vector<std::vector<int>> minCosts(cuts.size());
    for (int i = cuts.size() - 1, n = 1; i >= 0; --i, ++n) {
      minCosts[i].resize(n);
    }

    minCosts[cuts.size() - 1][0] = n - cuts[cuts.size() - 2];
    for (int i = cuts.size() - 2; i > 0; --i) {
      minCosts[i][0] = cuts[i + 1]  - cuts[i - 1];
    }
    minCosts[0][0] = cuts[1];

    return minCosts[0][cuts.size() - 1];
  }
};
