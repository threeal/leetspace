#include <algorithm>
#include <vector>

class Solution {
 public:
  int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
    std::sort(
        intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
          return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

    std::vector<int> nums{intervals[0][1] - 1, intervals[0][1]};
    for (std::size_t i{1}; i < intervals.size(); ++i) {
      if (intervals[i][0] > nums[nums.size() - 1]) {
        nums.push_back(intervals[i][1] - 1);
        nums.push_back(intervals[i][1]);
      } else if (intervals[i][0] > nums[nums.size() - 2]) {
        nums.push_back(intervals[i][1]);
      }
    }

    return nums.size();
  }
};
