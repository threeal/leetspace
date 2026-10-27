#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> createGrid(int m, int n) {
    return std::vector<std::string>(m, std::string(n, '.'));
  }
};
