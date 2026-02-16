#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseByType(std::string s) {
    std::size_t l{0}, rc{s.size() - 1}, rs{s.size() - 1};
    while (l < rc || l < rs) {
      if (s[l] >= 'a') {
        while (l < rc && s[rc] < 'a') --rc;
        if (l < rc) {
          std::swap(s[l], s[rc]);
          --rc;
        }
      } else {
        while (l < rs && s[rs] >= 'a') --rs;
        if (l < rs) {
          std::swap(s[l], s[rs]);
          --rs;
        }
      }
      ++l;
    }

    return s;
  }
};
