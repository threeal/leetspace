#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxTwoEvents(std::vector<std::vector<int>>& events) {
    std::sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    std::vector<int> eventMaxs(events.size());
    eventMaxs.back() = events.back()[2];

    for (std::size_t i{events.size() - 1}; i > 0; --i) {
      eventMaxs[i - 1] = std::max(events[i - 1][2], eventMaxs[i]);
    }

    int maxSum{0};
    for (std::size_t i{0}; i < events.size(); ++i) {
      std::size_t low{i + 1}, high{events.size() - 1};
      while (low < high) {
        const std::size_t mid{low + (high - low) / 2};
        if (events[mid][0] <= events[i][1]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }

      const int sum{
          events[high][0] > events[i][1]
              ? events[i][2] + eventMaxs[high]
              : events[i][2]};

      if (sum > maxSum) maxSum = sum;
    }

    return maxSum;
  }
};
