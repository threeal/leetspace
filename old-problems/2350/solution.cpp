#include <vector>

class Solution {
 public:
  int shortestSequence(std::vector<int>& rolls, int k) {
    return rolls.size() + k;
  }
};
