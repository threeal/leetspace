#include <string>

class Solution {
 public:
  int minNumberOfFrogs(std::string croakOfFrogs) {
    int min{0}, c{0}, r{0}, o{0}, a{0};

    for (const auto ch : croakOfFrogs) {
      switch (ch) {
        case 'c':
          if (++c > min) min = c;
          break;

        case 'r':
          if (++r > c) return -1;
          break;

        case 'o':
          if (++o > r) return -1;
          break;

        case 'a':
          if (++a > o) return -1;
          break;

        case 'k':
          if (o == 0) return -1;
          --c;
          --r;
          --o;
          --a;
      }
    }

    if (c > 0 || a > 0) return -1;
    return min;
  }
};
