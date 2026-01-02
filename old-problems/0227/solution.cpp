#include <stack>
#include <string>
#include <tuple>

class Solution {
 public:
  int calculate(std::string s) {
    std::stack<std::tuple<int, char>> operations;
    std::size_t i{0};
    while (true) {
      while (i < s.size() && s[i] == ' ') ++i;

      int num{0};
      while (s[i] >= '0') {
        num = num * 10 + (s[i] - '0');
        ++i;
      }

      while (i < s.size() && s[i] == ' ') ++i;
      if (i != s.size()) {
        while (!operations.empty() &&
               priority(std::get<1>(operations.top())) <= priority(s[i])) {
          const auto [prevNum, op] = operations.top();
          operations.pop();

          num = calculate(prevNum, op, num);
        }

        operations.push({num, s[i]});
        ++i;
      } else {
        while (!operations.empty()) {
          const auto [prevNum, op] = operations.top();
          operations.pop();

          num = calculate(prevNum, op, num);
        }

        return num;
      }
    }

    return -1;
  }

 private:
  static char priority(char op) {
    switch (op) {
      case '*':
      case '/':
        return 0;
    }
    return 1;
  }

  static int calculate(int a, char op, int b) {
    switch (op) {
      case '*':
        return a * b;

      case '+':
        return a + b;

      case '-':
        return a - b;

      case '/':
        return a / b;
    }

    return 0;
  }
};
