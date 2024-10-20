#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
    const auto compare =
        [&nums](
            const std::tuple<std::size_t, std::size_t>& a,
            const std::tuple<std::size_t, std::size_t>& b) {
          return nums[std::get<0>(a)][std::get<1>(a)] >
              nums[std::get<0>(b)][std::get<1>(b)];
        };

    std::priority_queue<
        std::tuple<std::size_t, std::size_t>,
        std::vector<std::tuple<std::size_t, std::size_t>>,
        decltype(compare)>
        elements(compare);

    int maxElement{-100000};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i][0] > maxElement) maxElement = nums[i][0];
      elements.push({i, 0});
    }

    std::vector<int> minRange{-100000, maxElement};
    while (true) {
      auto [i, j] = elements.top();
      if (maxElement - nums[i][j] < minRange[1] - minRange[0]) {
        minRange[0] = nums[i][j];
        minRange[1] = maxElement;
      }

      if (++j == nums[i].size()) break;
      if (nums[i][j] > maxElement) maxElement = nums[i][j];

      elements.pop();
      elements.push({i, j});
    }

    return minRange;
  }
};
