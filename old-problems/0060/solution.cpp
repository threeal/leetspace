#include <string>

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    return std::string(n, '0' + k % 10);
  }
};
