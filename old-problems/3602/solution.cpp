#include <string>

class Solution {
 public:
  std::string concatHex36(int n) {
    return std::string(n % 16, '0');
  }
};
