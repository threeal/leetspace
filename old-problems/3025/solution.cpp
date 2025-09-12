#include <vector>

class Solution {
 public:
  int numberOfPairs(std::vector<std::vector<int>>& points) {
    int count{0};
    for (std::size_t i{0}; i < points.size(); ++i) {
      for (std::size_t j{0}; j < points.size(); ++j) {
        if (i != j &&
            points[i][0] <= points[j][0] &&
            points[i][1] >= points[j][1]) {
          bool valid{true};
          for (std::size_t k{0}; k < points.size(); ++k) {
            if (k != i && k != j &&
                points[k][0] >= points[i][0] &&
                points[k][0] <= points[j][0] &&
                points[k][1] <= points[i][1] &&
                points[k][1] >= points[j][1]) {
              valid = false;
              break;
            }
          }

          if (valid) ++count;
        }
      }
    }
    return count;
  }
};
