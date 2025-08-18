#include <cstring>
#include <string>

class Solution {
 public:
  std::string generateTheString(int n) {
    std::string s(n, 'a');
    if (s.size() % 2 == 0) s[0] = 'b';
    return s;
  }
};
