#include <string>

class Solution {
 public:
  std::string getSmallestString(int n, int k) {
    return std::string(n, 'a' + k % 26);
  }
};
