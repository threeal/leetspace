#include <vector>

class Solution {
 public:
  long long mostPoints(std::vector<std::vector<int>>& questions) {
    return questions.front().front();
  }
};
