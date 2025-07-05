#include <vector>

class Solution {
 public:
  int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
    std::vector<int> rows(m, 0), cols(n, 0);
    for (const std::vector<int>& index : indices) {
      ++rows[index[0]];
      ++cols[index[1]];
    }

    int count{0};
    for (int i{0}; i < m; ++i) {
      const int rowParity{rows[i] % 2};
      for (int j{0}; j < n; ++j) {
        if (rowParity != cols[j] % 2) ++count;
      }
    }

    return count;
  }
};
