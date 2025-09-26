#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int maxValue(std::vector<std::vector<int>>& events, int k) {
    std::sort(events.begin(), events.end());

    std::vector<int> sums(events.size());
    for (std::size_t i{0}; i < events.size(); ++i) {
      sums[i] = events[i][2];
    }

    while (--k > 0) {
      int maxPrevSum{0};
      std::priority_queue<std::tuple<int, int>> prevEvents{};
      for (std::size_t i{0}; i < events.size(); ++i) {
        while (!prevEvents.empty()) {
          const auto [negEndDay, sum] = prevEvents.top();
          if (-negEndDay < events[i][0]) {
            if (sum > maxPrevSum) maxPrevSum = sum;
            prevEvents.pop();
          } else {
            break;
          }
        }

        prevEvents.push({-events[i][1], sums[i]});
        sums[i] = events[i][2] + maxPrevSum;
      }
    }

    return *std::max_element(sums.begin(), sums.end());
  }
};
