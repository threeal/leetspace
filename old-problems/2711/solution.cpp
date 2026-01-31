#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> differenceOfDistinctValues(
      std::vector<std::vector<int>>& grid) {
    for (std::size_t i{0}; i < grid.size(); ++i) {
      int brFreqs[51]{0}, brDistinct{0};
      std::size_t ii{i}, j{0};
      while (ii < grid.size() && j < grid[ii].size()) {
        if (++brFreqs[grid[ii][j]] == 1) ++brDistinct;
        ++ii, ++j;
      }

      int tlFreqs[51]{0}, tlDistinct{0};
      ii = i, j = 0;
      while (ii < grid.size() && j < grid[ii].size()) {
        const int num{grid[ii][j]};
        if (--brFreqs[num] == 0) --brDistinct;
        grid[ii][j] = std::abs(tlDistinct - brDistinct);
        if (++tlFreqs[num] == 1) ++tlDistinct;
        ++ii, ++j;
      }
    }

    for (std::size_t j{1}; j < grid[0].size(); ++j) {
      int brFreqs[51]{0}, brDistinct{0};
      std::size_t i{0}, jj{j};
      while (i < grid.size() && jj < grid[i].size()) {
        if (++brFreqs[grid[i][jj]] == 1) ++brDistinct;
        ++i, ++jj;
      }

      int tlFreqs[51]{0}, tlDistinct{0};
      i = 0, jj = j;
      while (i < grid.size() && jj < grid[i].size()) {
        const int num{grid[i][jj]};
        if (--brFreqs[num] == 0) --brDistinct;
        grid[i][jj] = std::abs(tlDistinct - brDistinct);
        if (++tlFreqs[num] == 1) ++tlDistinct;
        ++i, ++jj;
      }
    }

    return grid;
  }
};
