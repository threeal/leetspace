#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::vector<int> futures(101, -1);

    for (int i = temperatures.size() - 1; i >= 0; --i) {
      const auto temperature = temperatures[i];
      temperatures[i] = std::max(futures[temperature] - i, 0);
      std::fill_n(futures.begin(), temperature, i);
    }

    return temperatures;
  }
};
