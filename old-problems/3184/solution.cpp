#include <vector>

class Solution {
 public:
  int countCompleteDayPairs(std::vector<int>& hours) {
    int count{0};
    for (std::size_t i{0}; i < hours.size(); ++i) {
      for (std::size_t j{i + 1}; j < hours.size(); ++j) {
        if ((hours[i] + hours[j]) % 24 == 0) ++count;
      }
    }
    return count;
  }
};
