#include <vector>

class Solution {
 public:
  std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix) {
    std::vector<int> numbers{};
    for (const auto& row : matrix) {
      std::size_t min{0};
      for (std::size_t i{row.size() - 1}; i > 0; --i) {
        if (row[i] < row[min]) min = i;
      }

      for (const auto& otherRow : matrix) {
        if (otherRow[min] > row[min]) {
          min = row.size();
          break;
        }
      }

      if (min < row.size()) numbers.push_back(row[min]);
    }
    return numbers;
  }
};
