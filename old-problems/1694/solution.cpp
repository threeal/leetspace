#include <string>

class Solution {
 public:
  std::string reformatNumber(std::string number) {
    std::size_t l{0};
    for (std::size_t i{0}; i < number.size(); ++i) {
      if (number[i] >= '0') number[l++] = number[i];
    }

    std::size_t r{0};
    switch (l % 3) {
      case 0:
        r = l + l / 3 - 1;
        number.resize(r);
        number[--r] = number[--l];
        number[--r] = number[--l];
        number[--r] = number[--l];
        break;

      case 1:
        r = l + (l - 4) / 3 + 1;
        number.resize(r);
        number[--r] = number[--l];
        number[--r] = number[--l];
        number[--r] = '-';
        number[--r] = number[--l];
        number[--r] = number[--l];
        break;

      case 2:
        r = l + (l - 2) / 3;
        number.resize(r);
        number[--r] = number[--l];
        number[--r] = number[--l];
    }

    while (l > 0) {
      number[--r] = '-';
      number[--r] = number[--l];
      number[--r] = number[--l];
      number[--r] = number[--l];
    }

    return number;
  }
};
