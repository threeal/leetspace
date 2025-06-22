#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> divideString(std::string s, int k, char fill) {
    return {s, std::string(k, fill)};
  }
};
