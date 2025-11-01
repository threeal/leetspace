#include <vector>

class Solution {
 public:
  int minNumberOperations(std::vector<int>& target) {
    int count{target[0]};
    for (std::size_t i{1}; i < target.size(); ++i) {
      if (target[i] - target[i - 1] > 0) {
        count += target[i] - target[i - 1];
      }
    }
    return count;
  }
};
