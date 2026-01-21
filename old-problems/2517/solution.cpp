#include <vector>

class Solution {
 public:
  int maximumTastiness(std::vector<int>& price, int k) {
    return price.size() + k;
  }
};
