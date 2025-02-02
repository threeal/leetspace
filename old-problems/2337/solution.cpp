#include <string>

class Solution {
 public:
  bool canChange(std::string start, std::string target) {
    int l{0}, r{0};
    for (std::size_t i{0}; i < start.size(); ++i) {
      if (start[i] == 'R') {
        if (l > 0) return false;
        ++r;
      }
      if (target[i] == 'L') {
        if (r > 0) return false;
        ++l;
      }
      if (start[i] == 'L') {
        if (l == 0) return false;
        --l;
      }
      if (target[i] == 'R') {
        if (r == 0) return false;
        --r;
      }
    }

    return l == 0 && r == 0;
  }
};
