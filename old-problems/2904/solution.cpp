#include <cstring>
#include <string>

class Solution {
 public:
  std::string shortestBeautifulSubstring(std::string s, int k) {
    std::size_t l{0};
    while (l < s.size() && s[l] == '0') ++l;
    if (l == s.size()) return "";

    std::size_t r{l + 1};
    while (r < s.size() && k != 1) {
      if (s[r] == '1') --k;
      ++r;
    }

    if (k != 1) return "";

    std::size_t ll{l}, rr{r};
    while (r < s.size()) {
      if (s[r++] == '1') {
        while (s[++l] == '0') {
        }
        if (r - l <= rr - ll) {
          if (r - l < rr - ll ||
              strncmp(s.data() + l, s.data() + ll, r - l) < 0) {
            ll = l;
            rr = r;
          }
        }
      }
    }

    return s.substr(ll, rr - ll);
  }
};
