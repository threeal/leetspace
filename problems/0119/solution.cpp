#include <functional>
#include <vector>

class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    auto cache = std::vector(rowIndex + 1, std::vector<int>());
    for (int i = 0; i <= rowIndex; ++i) {
      cache[i].resize(i + 1);
    }

    const std::function<int(int, int)> fn = [&](int row, int index) {
      if (index < 0 || index > row) return 0;
      if (index == 0 || index == row) return 1;
      if (cache[row][index] <= 0) {
        cache[row][index] = fn(row - 1, index - 1) + fn(row - 1, index);
      }
      return cache[row][index];
    };

    std::vector<int> arr(rowIndex + 1);
    for (int i = 0; i <= rowIndex; ++i) {
      arr[i] = fn(rowIndex, i);
    }

    return arr;
  }
};
