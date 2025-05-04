#include <string>

class Solution {
 public:
  std::string interpret(std::string command) {
    std::size_t l{0}, r{0};
    while (r < command.size()) {
      if (command[r] == '(') {
        if (command[r + 1] == ')') {
          command[l++] = 'o';
          r += 2;
        } else {
          command[l++] = 'a';
          command[l++] = 'l';
          r += 4;
        }
      } else {
        command[l++] = 'G';
        ++r;
      }
    }
    command.resize(l);
    return command;
  }
};
