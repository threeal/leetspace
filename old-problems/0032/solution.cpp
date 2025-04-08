#include <stack>
#include <string>

class Solution {
 public:
  int longestValidParentheses(std::string s) {
    std::stack<std::size_t> stack{};
    stack.push(0);

    std::size_t longest{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == '(') {
        stack.push(i + 1);
      } else {
        stack.pop();
        if (stack.empty()) {
          stack.push(i + 1);
        } else if (i + 1 - stack.top() > longest) {
          longest = i + 1 - stack.top();
        }
      }
    }

    return longest;
  }
};
