#include <algorithm>
#include <stack>
#include <string>

class Solution {
 public:
  std::string reverseParentheses(std::string s) {
    // Reverse substrings based on the parentheses.
    std::stack<int> closers{};
    for (int i = s.size() - 1; i >= 0; --i) {
      switch (s[i]) {
        case ')':
          closers.push(i);
          break;

        case '(':
          std::reverse(s.begin() + i + 1, s.begin() + closers.top());
          closers.pop();
      }
    }

    // Remove any parentheses from the string.
    std::size_t out{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      switch (s[i]) {
        case ')':
        case '(':
          break;

        default:
          s[out] = s[i];
          ++out;
      }
    }
    s.resize(out);

    return s;
  }
};
