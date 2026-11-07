#include <algorithm>
#include <vector>

class Solution {
 public:
  int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(
        intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
          return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

    std::size_t remainings{intervals.size()};
    int max{intervals[0][1]};
    for (std::size_t i{1}; i < intervals.size(); ++i) {
      if (intervals[i][1] <= max) {
        --remainings;
      } else {
        max = intervals[i][1];
      }
    }

    return remainings;
  }
};
