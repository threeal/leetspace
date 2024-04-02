#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::vector<std::int32_t> futures(71, -1);

    for (std::int32_t i = temperatures.size() - 1; i >= 0; --i) {
      const auto temperature = temperatures[i] - 30;
      temperatures[i] = std::max(futures[temperature] - i, 0);
      std::fill_n(futures.begin(), temperature, i);
    }

    return temperatures;
  }
};
