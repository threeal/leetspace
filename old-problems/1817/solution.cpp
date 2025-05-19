#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> findingUsersActiveMinutes(
      std::vector<std::vector<int>>& logs, int k) {
    std::sort(logs.begin(), logs.end());

    std::vector<int> output(k, 0);
    std::size_t i{0};
    while (i < logs.size()) {
      int uam{1};

      ++i;
      while (i < logs.size() && logs[i][0] == logs[i - 1][0]) {
        if (logs[i][1] != logs[i - 1][1]) ++uam;
        ++i;
      }

      ++output[uam - 1];
    }

    return output;
  }
};
