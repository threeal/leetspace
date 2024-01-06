#include <functional>
#include <vector>

class Solution {
 public:
  int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
    std::vector<int> cache(profit.size(), -1);
    const std::function<int(int)> fn = [&](std::size_t i) {
      if (cache[i] >= 0) return cache[i];

      int maxProfit = profit[i];
      for (std::size_t j = 0; j < profit.size(); ++j) {
        if (startTime[j] < endTime[i]) continue;
        maxProfit = std::max(maxProfit, profit[i] + fn(j));
      }

      return cache[i] = maxProfit;
    };

    int maxProfit = 0;
    for (std::size_t i = 0; i < profit.size(); ++i) {
      maxProfit = std::max(maxProfit, fn(i));
    }

    return maxProfit;
  }
};
