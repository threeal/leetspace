#include <string>
#include <vector>

struct Specials {
  int a;
  int b;
  int c;
};

class Solution {
 public:
  int maximumLength(std::string s) {
    std::vector<Specials> specials(26, {.a = 0, .b = 0, .c = 0});

    int prev{0};
    for (int i{1}; i <= static_cast<int>(s.size()); ++i) {
      if (s[i] != s[i - 1]) {
        auto& special = specials[s[i - 1] - 'a'];
        if (i - prev > special.a) {
          special.c = special.b;
          special.b = special.a;
          special.a = i - prev;
        } else if (i - prev > special.b) {
          special.c = special.b;
          special.b = i - prev;
        } else if (i - prev > special.c) {
          special.c = i - prev;
        }
        prev = i;
      }
    }

    int max{0};
    for (const auto special : specials) {
      if (special.a > 0) {
        if (special.a - 2 > max) max = special.a - 2;

        if (special.b > 0) {
          if (special.a == special.b) {
            if (special.a - 1 > max) max = special.a - 1;
          } else {
            if (special.b > max) max = special.b;
          }

          if (special.c > 0) {
            if (special.c > max) max = special.c;
          }
        }
      }
    }

    return max == 0 ? -1 : max;
  }
};
