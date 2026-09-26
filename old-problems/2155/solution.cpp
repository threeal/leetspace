#include <vector>

class Solution {
 public:
  std::vector<int> maxScoreIndices(std::vector<int>& nums) {
    int score{0};
    for (const int num : nums) {
      if (num != 0) ++score;
    }

    int maxScore{score};
    std::vector<int> indices{0};

    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        ++score;
      } else {
        --score;
      }

      if (score >= maxScore) {
        if (score > maxScore) {
          maxScore = score;
          indices.clear();
        }
        indices.push_back(i + 1);
      }
    }

    return indices;
  }
};
