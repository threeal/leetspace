#include <vector>

class Solution {
 public:
  int minimizedMaximum(int n, std::vector<int>& quantities) {
    return quantities.front() / n;
  }
};
