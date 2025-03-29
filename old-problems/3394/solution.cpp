#include <vector>

class Solution {
 public:
  bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
    return rectangles.size() == static_cast<std::size_t>(n);
  }
};
