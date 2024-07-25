#include <string>

class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(std::string word, int k) {
    return word.size() / k;
  }
};
