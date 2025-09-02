#include <vector>

class Solution {
 public:
  int maxFreeTime(
      int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
    const std::size_t n{startTime.size()};

    int maxFree{0}, prevFree{startTime[0]};
    for (std::size_t i{1}; i < n; ++i) {
      const int free{startTime[i] - endTime[i - 1]};
      if (free + prevFree > maxFree) maxFree = free + prevFree;
      prevFree = free;
    }

    const int free{eventTime - endTime[n - 1]};
    if (free + prevFree > maxFree) maxFree = free + prevFree;

    if (n >= 2) {
      int maxEmpty{startTime[0]};
      for (std::size_t i{2}; i < n; ++i) {
        if (endTime[i - 1] - startTime[i - 1] <= maxEmpty) {
          const int free{startTime[i] - endTime[i - 2]};
          if (free > maxFree) maxFree = free;
        }

        const int empty{startTime[i - 1] - endTime[i - 2]};
        if (empty > maxEmpty) maxEmpty = empty;
      }

      if (endTime[n - 1] - startTime[n - 1] <= maxEmpty) {
        const int free{eventTime - endTime[n - 2]};
        if (free > maxFree) maxFree = free;
      }

      maxEmpty = eventTime - endTime[n - 1];
      for (std::size_t i{n - 1}; i >= 2; --i) {
        if (endTime[i - 1] - startTime[i - 1] <= maxEmpty) {
          const int free{startTime[i] - endTime[i - 2]};
          if (free > maxFree) maxFree = free;
        }

        const int empty{startTime[i] - endTime[i - 1]};
        if (empty > maxEmpty) maxEmpty = empty;
      }

      if (endTime[0] - startTime[0] <= maxEmpty) {
        const int free{startTime[1]};
        if (free > maxFree) maxFree = free;
      }
    }

    return maxFree;
  }
};
