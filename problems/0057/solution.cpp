#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    std::vector<std::vector<int>> newIntervals;
    newIntervals.reserve(intervals.size());

    auto it = intervals.begin();
    while (it != intervals.end() && (*it)[1] < newInterval[0]) {
      newIntervals.push_back(*it);
      ++it;
    }

    while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
      if ((*it)[0] < newInterval[0]) newInterval[0] = (*it)[0];
      if ((*it)[1] > newInterval[1]) newInterval[1] = (*it)[1];
      ++it;
    }
    newIntervals.push_back(newInterval);

    while (it != intervals.end()) {
      newIntervals.push_back(*it);
      ++it;
    }

    return newIntervals;
  }
};
