#include <string>

class Solution {
 public:
  int maxNumberOfBalloons(std::string text) {
    int b{0}, a{0}, l{0}, o{0}, n{0};
    for (char c : text) {
      switch (c) {
        case 'b':
          ++b;
          break;

        case 'a':
          ++a;
          break;

        case 'l':
          ++l;
          break;

        case 'o':
          ++o;
          break;

        case 'n':
          ++n;
          break;
      }
    }

    int max{b};
    if (a < max) max = a;
    if (l / 2 < max) max = l / 2;
    if (o / 2 < max) max = o / 2;
    if (n < max) max = n;

    return max;
  }
};
