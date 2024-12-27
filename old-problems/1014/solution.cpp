#include <vector>

class Solution {
 public:
  int maxScoreSightseeingPair(std::vector<int>& values) {
    int maxScore{0}, maxVal{values[0]};
    for (std::size_t i{1}; i < values.size(); ++i) {
      --maxVal;
      if (maxVal + values[i] > maxScore) maxScore = maxVal + values[i];
      if (values[i] >= maxVal) maxVal = values[i];
    }
    return maxScore;
  }
};
