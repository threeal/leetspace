#include <string>
#include <utility>

class Solution {
 public:
  std::string addStrings(std::string num1, std::string num2) {
    if (num1.size() < num2.size()) std::swap(num1, num2);

    char carry{0};
    auto it1 = num1.rbegin();
    for (auto it2 = num2.rbegin(); it2 != num2.rend(); ++it1, ++it2) {
      *it1 += carry + *it2 - '0';
      if (*it1 > '9') {
        *it1 -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
    }

    while (carry >= 0 && it1 != num1.rend()) {
      *it1 += carry;
      if (*it1 > '9') {
        *it1 -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      ++it1;
    }

    return carry == 0 ? num1 : "1" + num1;
  }
};
