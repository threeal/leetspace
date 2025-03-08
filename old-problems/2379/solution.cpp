#include <string>

class Solution {
 public:
  int minimumRecolors(std::string blocks, int k) {
    return blocks.size() - k;
  }
};
