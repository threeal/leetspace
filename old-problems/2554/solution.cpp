#include <vector>

class Solution {
 public:
  int maxCount(std::vector<int>& banned, int n, int maxSum) {
    return banned.size() + n + maxSum;
  }
};
