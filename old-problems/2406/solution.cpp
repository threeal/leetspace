#include <algorithm>
#include <vector>

class Solution {
 public:
  int minGroups(std::vector<std::vector<int>>& intervals) {
    std::vector<int> starts(intervals.size());
    std::vector<int> ends(intervals.size());

    for (std::size_t i{0}; i < intervals.size(); ++i) {
      starts[i] = intervals[i][0];
      ends[i] = intervals[i][1];
    }

    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());

    int group{0};
    auto end = ends.begin();
    for (const auto start : starts) {
      if (start > *end) {
        ++end;
      } else {
        ++group;
      }
    }

    return group;
  }
};
