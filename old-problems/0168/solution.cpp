#include <string>

class Solution {
 public:
  std::string convertToTitle(int columnNumber) {
    return std::string(columnNumber, '.');
  }
};
