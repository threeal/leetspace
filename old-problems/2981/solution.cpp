#include <queue>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int maximumLength(std::string s) {
    std::unordered_map<char, std::priority_queue<int>> charSpecials{};

    std::size_t prev{0};
    for (std::size_t i{1}; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        charSpecials[s[i - 1]].push(i - prev);
        prev = i;
      }
    }
    charSpecials[s.back()].push(s.size() - prev);

    int max{0};
    for (auto& [c, specials] : charSpecials) {
      const auto a = specials.top();
      specials.pop();

      if (a - 2 > max) max = a - 2;

      if (!specials.empty()) {
        const auto b = specials.top();
        specials.pop();

        if (a == b) {
          if (a - 1 > max) max = a - 1;
        } else {
          if (b > max) max = b;
        }

        if (!specials.empty()) {
          const auto c = specials.top();
          specials.pop();

          if (c > max) max = c;
        }
      }
    }

    return max == 0 ? -1 : max;
  }
};
