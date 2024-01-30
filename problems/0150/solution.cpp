#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> prevs;

    for (const auto& token : tokens) {
      if (token == "+") {
        const auto val = prevs.top();
        prevs.pop();
        prevs.top() += val;
      } else if (token == "-") {
        const auto val = prevs.top();
        prevs.pop();
        prevs.top() -= val;
      } else if (token == "*") {
        const auto val = prevs.top();
        prevs.pop();
        prevs.top() *= val;
      } else if (token == "/") {
        const auto val = prevs.top();
        prevs.pop();
        prevs.top() /= val;
      } else {
        prevs.push(std::stoi(token));
      }
    }

    return prevs.top();
  }
};
