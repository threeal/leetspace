#include <vector>

class Solution {
 public:
  int findJudge(int n, std::vector<std::vector<int>>& trust) {
    std::vector<int> trustCount(n, 0);
    std::vector<bool> trustAnyone(n, false);

    for (const auto& t : trust) {
      trustAnyone[t[0] - 1] = true;
      ++trustCount[t[1] - 1];
    }

    for (int i = 0; i < n; ++i) {
      if (trustCount[i] == n - 1 && !trustAnyone[i]) {
        return i + 1;
      }
    }

    return -1;
  }
};
