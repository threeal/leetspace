#include <stack>
#include <string>

class Solution {
 public:
  std::string robotWithString(std::string s) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    char smallC{'a'};
    while (freqs[smallC - 'a'] == 0) ++smallC;

    std::size_t n{0};
    std::stack<char> t{};
    for (const char c : s) {
      --freqs[c - 'a'];
      if (c == smallC) {
        s[n++] = smallC;
        while (smallC <= 'z' && freqs[smallC - 'a'] == 0) {
          ++smallC;
          while (!t.empty() && t.top() <= smallC) {
            s[n++] = t.top();
            t.pop();
          }
        }
      } else {
        t.push(c);
      }
    }

    while (!t.empty()) {
      s[n++] = t.top();
      t.pop();
    }

    return s;
  }
};
