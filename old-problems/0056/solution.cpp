#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::size_t i{0};
    for (std::size_t j{1}; j < intervals.size(); ++j) {
      if (intervals[i][1] >= intervals[j][0]) {
        intervals[i][1] = std::max(intervals[i][1], intervals[j][1]);
      } else {
        intervals[++i] = intervals[j];
      }
    }

    intervals.resize(i + 1);
    return intervals;
  }
};
