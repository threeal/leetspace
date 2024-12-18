#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCount(std::vector<int>& banned, int n, int maxSum) {
    std::sort(banned.begin(), banned.end());
    auto it = banned.begin();

    int count{0};
    for (int i = 1; i <= n && i <= maxSum; ++i) {
      if (it != banned.end() && *it == i) {
        ++it;
        continue;
      }

      maxSum -= i;
      ++count;
    }

    return count;
  }
};
