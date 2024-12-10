#include <string>
#include <unordered_map>

struct Specials {
  int a;
  int b;
  int c;
};

class Solution {
 public:
  int maximumLength(std::string s) {
    std::unordered_map<char, Specials> specials{};

    int prev{0};
    for (int i{1}; i <= static_cast<int>(s.size()); ++i) {
      if (s[i] != s[i - 1]) {
        auto it = specials.find(s[i - 1]);
        if (it == specials.end()) {
          specials.emplace(s[i - 1], Specials{.a = i - prev, .b = 0, .c = 0});
        } else {
          if (i - prev > it->second.a) {
            it->second.c = it->second.b;
            it->second.b = it->second.a;
            it->second.a = i - prev;
          } else if (i - prev > it->second.b) {
            it->second.c = it->second.b;
            it->second.b = i - prev;
          } else if (i - prev > it->second.c) {
            it->second.c = i - prev;
          }
        }
        prev = i;
      }
    }

    int max{0};
    for (const auto& [c, s] : specials) {
      if (s.a - 2 > max) max = s.a - 2;

      if (s.b > 0) {
        if (s.a == s.b) {
          if (s.a - 1 > max) max = s.a - 1;
        } else {
          if (s.b > max) max = s.b;
        }

        if (s.c > 0) {
          if (s.c > max) max = s.c;
        }
      }
    }

    return max == 0 ? -1 : max;
  }
};
