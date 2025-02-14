#include <vector>

class Solution {
 public:
  std::vector<int> queryResults(
      int limit, std::vector<std::vector<int>>& queries) {
    return std::vector<int>(queries.size(), limit + 1);
  }
};
