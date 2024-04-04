#include <string>

class Solution {
 public:
  int maxDepth(std::string s) {
    int maxCount{0};
    int count{0};

    char* c{s.data()};
    while (*c != 0) {
      switch (*c) {
        case '(':
          ++count;
          if (count > maxCount) maxCount = count;
          break;

        case ')':
          --count;
          break;
      }
      ++c;
    }

    return maxCount;
  }
};
