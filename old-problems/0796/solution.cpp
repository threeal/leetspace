#include <string>

class Solution {
 public:
  bool rotateString(std::string s, std::string goal) {
    for (int i = s.size() - 1; i >= 0; --i) {
      if (!compare(s.data() + i, goal.data(), s.size() - i)) continue;
      if (!compare(s.data(), goal.data() + s.size() - i, i)) continue;
      return true;
    }

    return false;
  }

  bool compare(char* a, char* b, int bSize) {
    for (int i = bSize - 1; i >= 0; --i) {
      if (a[i] != b[i]) return false;
    }

    return true;
  }
};
