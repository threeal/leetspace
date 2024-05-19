#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  double mincostToHireWorkers(std::vector<int>& qualities, std::vector<int>& wages, int k) {
    const int n = qualities.size();

    std::vector<std::pair<double, int>> ratios(qualities.size());
    for (int i{0}; i < n; ++i) {
      ratios[i].first = static_cast<double>(wages[i]) / static_cast<double>(qualities[i]);
      ratios[i].second = qualities[i];
    }

    std::sort(ratios.begin(), ratios.end());

    double maxRatio{0.0};
    int totalQualities{0};
    std::priority_queue<int> maxQualities{};
    for (int i{0}; i < k; ++i) {
      if (ratios[i].first > maxRatio) maxRatio = ratios[i].first;
      totalQualities += ratios[i].second;
      maxQualities.push(ratios[i].second);
    }

    double minCost{maxRatio * totalQualities};
    for (int i{k}; i < n; ++i) {
      if (ratios[i].first > maxRatio) maxRatio = ratios[i].first;

      totalQualities += ratios[i].second - maxQualities.top();
      maxQualities.pop();
      maxQualities.push(ratios[i].second);

      if (maxRatio * totalQualities < minCost) {
        minCost = maxRatio * totalQualities;
      }
    }

    return minCost;
  }
};
