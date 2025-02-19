#include <string>

class Solution {
 public:
  std::string getHappyString(int n, int k) {
    std::string s(n, 'a');
    findHappyString(s, 0, k);
    return k == 0 ? s : "";
  }

  void findHappyString(std::string& s, std::size_t i, int& k) {
    for (char c{'a'}; c <= 'c'; ++c) {
      if (i > 0 && s[i - 1] == c) continue;
      s[i] = c;
      if (i + 1 < s.size()) {
        findHappyString(s, i + 1, k);
      } else {
        --k;
      }
      if (k == 0) return;
    }
  }
};
