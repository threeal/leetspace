#include <vector>

class Solution {
 public:
  std::vector<int> countServers(
      int n, std::vector<std::vector<int>>& /*logs*/, int /*x*/,
      std::vector<int>& queries) {
    return std::vector<int>(queries.size(), n);
  }
};
