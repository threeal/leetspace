#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCasePermutation(std::string s) {
    std::vector<std::string> out{};
    explore(out, s, 0);
    return out;
  }

 private:
  static void explore(
      std::vector<std::string>& out, const std::string& s, std::size_t i) {
    if (i == s.size()) {
      out.push_back(s);
    } else {
      explore(out, s, i + 1);
      if (s[i] > '9') {
        auto ss = s;
        ss[i] += s[i] <= 'Z' ? 'a' - 'A' : 'A' - 'a';
        explore(out, ss, i + 1);
      }
    }
  }
};
