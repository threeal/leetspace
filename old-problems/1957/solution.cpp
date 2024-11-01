#include <string>

class Solution {
 public:
  std::string makeFancyString(std::string s) {
    std::string out{};
    out.reserve(s.size());

    char prev{0};
    bool twice{false};
    for (const auto c : s) {
      if (c != prev) {
        prev = c;
        twice = false;
      } else {
        if (twice) continue;
        twice = true;
      }
      out += c;
    }

    return out;
  }
};
