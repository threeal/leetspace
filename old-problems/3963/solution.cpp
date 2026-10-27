#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> createGrid(int m, int n) {
    std::string str(n, '#');
    str[0] = '.';

    std::vector<std::string> grid(m, str);
    std::fill(grid.back().begin(), grid.back().end(), '.');

    return grid;
  }
};
