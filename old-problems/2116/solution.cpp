#include <string>

class Solution {
 public:
  bool canBeValid(std::string s, std::string locked) {
    if (locked.size() % 2 == 1) return false;

    int unlocked{0}, opens{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (locked[i] == '0') {
        ++unlocked;
      } else if (s[i] == '(') {
        ++opens;
      } else if (opens > 0) {
        --opens;
      } else if (unlocked > 0) {
        --unlocked;
      } else {
        return false;
      }
    }

    int balance{0};
    for (int i = s.size() - 1; i >= 0; --i) {
      if (locked[i] == '0') {
        --balance;
        --unlocked;
      } else if (s[i] == ')') {
        --balance;
      } else {
        ++balance;
        --opens;
      }

      if (balance > 0) return false;
      if (unlocked == 0 && opens == 0) break;
    }

    return true;
  }
};
