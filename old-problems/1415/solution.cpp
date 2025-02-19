#include <string>

class Solution {
 public:
  std::string getHappyString(int n, int k) {
    return std::string(n, 'a' + k % 3);
  }
};
