#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  double maxAverageRatio(
      std::vector<std::vector<int>>& classes, int extraStudents) {
    std::priority_queue<std::tuple<double, int, int>> ratios{};
    for (const auto& cls : classes) {
      const double a = cls[0], b = cls[1];
      ratios.push({(b - a) / (b * b + b), cls[0], cls[1]});
    }

    while (extraStudents > 0) {
      auto ratio = ratios.top();
      ratios.pop();

      const double a = ++std::get<1>(ratio), b = ++std::get<2>(ratio);
      std::get<0>(ratio) = (b - a) / (b * b + b);

      ratios.push(ratio);
      --extraStudents;
    }

    double sum{0.0};
    while (!ratios.empty()) {
      sum += (double)std::get<1>(ratios.top()) / (double)std::get<2>(ratios.top());
      ratios.pop();
    }

    return sum / classes.size();
  }
};
