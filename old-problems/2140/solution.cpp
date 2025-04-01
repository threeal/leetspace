#include <vector>

class Solution {
 public:
  long long mostPoints(std::vector<std::vector<int>>& questions) {
    std::vector<long long> points(questions.size());
    points.back() = questions.back()[0];

    for (std::size_t i{questions.size() - 1}; i > 0; --i) {
      points[i - 1] = questions[i - 1][0];
      if (i + questions[i - 1][1] < questions.size()) {
        points[i - 1] += points[i + questions[i - 1][1]];
      }
      if (points[i] > points[i - 1]) points[i - 1] = points[i];
    }

    return points.front();
  }
};
