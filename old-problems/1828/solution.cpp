#include <vector>

class Solution {
 public:
  std::vector<int> countPoints(
      std::vector<std::vector<int>>& points,
      std::vector<std::vector<int>>& queries) {
    std::vector<int> output(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      int count{0};
      const int r2{queries[i][2] * queries[i][2]};
      for (const std::vector<int>& point : points) {
        const int x{point[0] - queries[i][0]};
        const int y{point[1] - queries[i][1]};
        if (x * x + y * y <= r2) ++count;
      }
      output[i] = count;
    }
    return output;
  }
};
