#include <string>

class Solution {
 public:
  int passwordStrength(std::string password) {
    int strength{0};
    std::uint32_t lower{0}, upper{0}, digit{0}, special{0};
    for (char c : password) {
      if (c >= 'a') {
        if ((lower & (1 << (c - 'a'))) == 0) {
          lower |= 1 << (c - 'a');
          ++strength;
        }
      } else if (c >= 'A') {
        if ((upper & (1 << (c - 'A'))) == 0) {
          upper |= 1 << (c - 'A');
          strength += 2;
        }
      } else if (c >= '0') {
        if (c == '@') {
          if ((special & 2) == 0) {
            special |= 2;
            strength += 5;
          }
        } else {
          if ((digit & (1 << (c - '0'))) == 0) {
            digit |= 1 << (c - '0');
            strength += 3;
          }
        }
      } else {
        switch (c) {
          case '!':
            if ((special & 1) == 0) {
              special |= 1;
              strength += 5;
            }
            break;

          case '#':
            if ((special & 4) == 0) {
              special |= 4;
              strength += 5;
            }
            break;

          case '$':
            if ((special & 8) == 0) {
              special |= 8;
              strength += 5;
            }
            break;
        }
      }
    }
    return strength;
  }
};
