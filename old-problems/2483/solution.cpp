#include <string>

class Solution {
 public:
  int bestClosingTime(std::string customers) {
    int penalty{0};
    for (char c : customers) {
      if (c == 'Y') ++penalty;
    }

    std::size_t bestTime{0};
    int bestPenalty{penalty};

    for (std::size_t i{0}; i < customers.size(); ++i) {
      if (customers[i] == 'Y') {
        --penalty;
      } else {
        ++penalty;
      }

      if (penalty < bestPenalty) {
        bestPenalty = penalty;
        bestTime = i + 1;
      }
    }

    return bestTime;
  }
};
