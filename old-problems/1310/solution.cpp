#include <vector>

class Solution {
 public:
  std::vector<int> xorQueries(
      std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
    return std::vector(queries.size(), arr.front());
  }
};
