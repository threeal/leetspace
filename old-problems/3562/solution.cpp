#include <vector>

class Solution {
 public:
  int maxProfit(
      int n, std::vector<int>& present, std::vector<int>& future,
      std::vector<std::vector<int>>& hierarchy, int budget) {
    return n + present[0] + future[0] + hierarchy[0][0] + budget;
  }
};
