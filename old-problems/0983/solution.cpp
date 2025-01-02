#include <algorithm>
#include <vector>

class Solution {
 public:
  int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
    std::vector<int> prices(days.size());
    prices[0] = std::min(std::min(costs[0], costs[1]), costs[2]);

    for (std::size_t i{1}, i7{0}, i30{0}; i < days.size(); ++i) {
      while (days[i7] + 7 <= days[i]) ++i7;
      while (days[i30] + 30 <= days[i]) ++i30;
      prices[i] = std::min(
          std::min(
              costs[0] + prices[i - 1],
              costs[1] + (i7 > 0 ? prices[i7 - 1] : 0)),
          costs[2] + (i30 > 0 ? prices[i30 - 1] : 0));
    }

    return prices.back();
  }
};
