#include <queue>
#include <string>

class Solution {
 public:
  std::string clearStars(std::string s) {
    std::priority_queue<std::tuple<char, std::size_t>> queue{};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == '*') {
        s[std::get<1>(queue.top())] = '*';
        queue.pop();
      } else {
        queue.push({'z' - s[i], i});
      }
    }

    std::size_t n{0};
    for (const char c : s) {
      if (c != '*') s[n++] = c;
    }
    s.resize(n);

    return s;
  }
};
