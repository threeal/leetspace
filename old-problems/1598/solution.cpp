#include <string>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<std::string>& logs) {
    int level{0};
    for (const auto& log : logs) {
      if (log[0] == '.') {
        if (log[1] == '.' && level > 0) --level;
      } else {
        ++level;
      }
    }
    return level;
  }
};
