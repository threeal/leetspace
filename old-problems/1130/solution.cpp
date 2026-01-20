#include <limits>
#include <vector>

struct ValCost {
  int val;
  int cost;
};

class Solution {
 public:
  int mctFromLeafValues(std::vector<int>& arr) {
    std::vector<std::vector<ValCost>> values(arr.size());

    values[0].resize(arr.size());
    for (std::size_t i{0}; i < arr.size(); ++i) {
      values[0][i].val = arr[i];
    }

    for (std::size_t i{1}; i < values.size(); ++i) {
      values[i].resize(arr.size() - i);
      for (std::size_t j{0}; j < values[i].size(); ++j) {
        int maxVal{0}, minCost{std::numeric_limits<int>::max()};
        for (std::size_t k{0}; k < i; ++k) {
          const ValCost& left{values[k][j]};
          const ValCost& right{values[i - k - 1][j + k + 1]};

          const int val{std::max(left.val, right.val)};
          if (val > maxVal) maxVal = val;

          const int cost{left.cost + right.cost + left.val * right.val};
          if (cost < minCost) minCost = cost;
        }

        values[i][j].val = maxVal;
        values[i][j].cost = minCost;
      }
    }

    return values.back().back().cost;
  }
};
