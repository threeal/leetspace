#include <vector>

class Solution {
 public:
  int maxScoreSightseeingPair(std::vector<int>& values) {
    int maxScore{0}, i{0};
    for (int j{1}; j < static_cast<int>(values.size()); ++j) {
      const auto score = values[i] + values[j] + i - j;
      if (score > maxScore) maxScore = score;
      if (values[j] >= values[i] + i - j) i = j;
    }
    return maxScore;
  }
};
