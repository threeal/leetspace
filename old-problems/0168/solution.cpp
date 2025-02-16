#include <algorithm>
#include <string>

class Solution {
 public:
  std::string convertToTitle(int columnNumber) {
    std::string str{};
    while (columnNumber > 0) {
      --columnNumber;
      str += 'A' + columnNumber % 26;
      columnNumber /= 26;
    }
    std::reverse(str.begin(), str.end());
    return str;
  }
};
