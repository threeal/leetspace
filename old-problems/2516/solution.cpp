#include <string>

class Solution {
 public:
  int takeCharacters(std::string s, int k) {
    std::size_t r{s.size()};
    int a{0}, b{0}, c{0};
    while ((a < k || b < k || c < k) && r > 0) {
      --r;
      switch (s[r]) {
        case 'a':
          ++a;
          break;
        case 'b':
          ++b;
          break;
        case 'c':
          ++c;
          break;
      }
    }

    if (a < k || b < k || c < k) return -1;

    int minTime = s.size() - r;
    for (std::size_t l{0}; l < s.size(); ++l) {
      switch (s[l]) {
        case 'a':
          ++a;
          break;
        case 'b':
          ++b;
          break;
        case 'c':
          ++c;
          break;
      }

    repeat:
      if (r < s.size()) {
        switch (s[r]) {
          case 'a':
            if (a > k) {
              --a;
              ++r;
              goto repeat;
            }
            break;

          case 'b':
            if (b > k) {
              --b;
              ++r;
              goto repeat;
            }
            break;

          case 'c':
            if (c > k) {
              --c;
              ++r;
              goto repeat;
            }
            break;
        }
      }

      if (l >= r) break;

      const int time = 1 + l + s.size() - r;
      if (time < minTime) minTime = time;
    }

    return minTime;
  }
};
