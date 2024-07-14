#include <cstdint>
#include <string>

class Solution {
 public:
  std::string reformatDate(std::string date) {
    auto c = date.data();

    char d1{'0'}, d2{'0'};
    if (c[1] > '9') {
      d2 = c[0];
      c += 4;
    } else {
      d1 = c[0];
      d2 = c[1];
      c += 5;
    }

    char m1{'0'}, m2{'0'};
    switch (c[0]) {
      case 'J':
        m2 = c[1] == 'a' ? '1' : (c[2] == 'n' ? '6' : '7');
        break;

      case 'F':
        m2 = '2';
        break;

      case 'M':
        m2 = c[2] == 'r' ? '3' : '5';
        break;

      case 'A':
        m2 = c[1] == 'p' ? '4' : '8';
        break;

      case 'S':
        m2 = '9';
        break;

      case 'O':
        m1 = '1';
        break;

      case 'N':
        m1 = '1';
        m2 = '1';
        break;

      case 'D':
        m1 = '1';
        m2 = '2';
        break;
    }

    auto s = date.data();
    s[0] = c[4];
    s[1] = c[5];
    s[2] = c[6];
    s[3] = c[7];
    s[4] = '-';
    s[5] = m1;
    s[6] = m2;
    s[7] = '-';
    s[8] = d1;
    s[9] = d2;

    date.resize(10);
    return date;
  }
};
