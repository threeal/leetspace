#include <vector>

class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> row(rowIndex + 1);
    for (int i{0}; i <= rowIndex; ++i) {
      row[i] = 1;
      for (int j{i - 1}; j > 0; --j) row[j] += row[j - 1];
    }
    return row;
  }
};
