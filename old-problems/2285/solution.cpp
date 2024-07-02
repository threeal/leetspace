#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
    std::vector<int> counts(n, 0);
    for (const auto& road : roads) {
      ++counts[road[0]];
      ++counts[road[1]];
    }

    std::sort(counts.begin(), counts.end());

    long long importance{0};
    long long id{1};
    for (const auto count : counts) {
      importance += id * count;
      ++id;
    }

    return importance;
  }
};
