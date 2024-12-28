#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> maximumBeauty(
      std::vector<std::vector<int>>& items, std::vector<int>& queries) {
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] >= b[1] : a[0] < b[0];
    });

    int maxBeauty{0};
    for (auto& item : items) {
      if (item[1] >= maxBeauty) {
        maxBeauty = item[1];
      } else {
        item[1] = maxBeauty;
      }
    }

    std::vector<int> answers(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      const auto it = std::lower_bound(
          items.rbegin(), items.rend(), queries[i],
          [](const auto& item, int price) {
            return item[0] > price;
          });

      answers[i] = it == items.rend() ? 0 : (*it)[1];
    }

    return answers;
  }
};
