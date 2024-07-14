#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumCost(std::vector<int>& cost) {
    std::sort(cost.begin(), cost.end());

    int total{0};
    int i = cost.size() - 2;
    while (i >= 0) {
      total += cost[i] + cost[i + 1];
      i -= 3;
    }
    if (i == -1) total += cost[0];

    return total;
  }
};
