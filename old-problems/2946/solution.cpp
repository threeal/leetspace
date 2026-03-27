#include <vector>

class Solution {
 public:
  bool areSimilar(std::vector<std::vector<int>>& mat, int k) {
    return mat.empty() && k == 0;
  }
};
