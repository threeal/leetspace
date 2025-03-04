#include <string>
#include <vector>

class Solution {
 public:
  int calPoints(std::vector<std::string>& operations) {
    int totalScore{0};

    std::vector<int> scores(operations.size());
    std::size_t scoresSize{0};

    for (const auto& op : operations) {
      switch (op[0]) {
        case '+':
          scores[scoresSize] = scores[scoresSize - 1] + scores[scoresSize - 2];
          totalScore += scores[scoresSize];
          ++scoresSize;
          break;

        case 'D':
          scores[scoresSize] = scores[scoresSize - 1] * 2;
          totalScore += scores[scoresSize];
          ++scoresSize;
          break;

        case 'C':
          totalScore -= scores[--scoresSize];
          break;

        default:
          scores[scoresSize] = std::stoi(op);
          totalScore += scores[scoresSize];
          ++scoresSize;
      };
    }

    return totalScore;
  }
};
