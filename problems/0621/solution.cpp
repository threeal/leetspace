#include <algorithm>
#include <vector>

class Solution {
 public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::vector<int> counts(26, 0);
    for (const auto task : tasks) {
      ++counts[task - 'A'];
    }

    std::sort(counts.begin(), counts.end(), std::greater<int>());

    int maxIntervals = counts[0] - 1;
    int intervals = maxIntervals * n;
    for (int i = 1; i < 26; ++i) {
      intervals -= std::min(maxIntervals, counts[i]);
    }

    return tasks.size() + std::max(0, intervals);
  }
};
