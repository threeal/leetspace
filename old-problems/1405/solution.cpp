#include <string>

class Solution {
 public:
  std::string longestDiverseString(int a, int b, int c) {
    std::string s;
    s.reserve(a + b + c);

    if (a >= b && a >= c) {
      if (a == 1) {
        s += 'a';
        a = 0;
      } else {
        s += "aa";
        a -= 2;
      }
    } else if (b >= a && b >= c) {
      if (b == 1) {
        s += 'b';
        b = 0;
      } else {
        s += "bb";
        b -= 2;
      }
    } else {
      if (c == 1) {
        s += 'c';
        c = 0;
      } else {
        s += "cc";
        c -= 2;
      }
    }

    while (a > 0 || b > 0 || c > 0) {
      if (s.back() == 'a') {
        if (b >= c) {
          if (b == 0) break;
          if (b >= 2 && b + c >= a) {
            s += "bb";
            b -= 2;
          } else {
            s += 'b';
            --b;
          }
        } else {
          if (c == 0) break;
          if (c >= 2 && b + c >= a) {
            s += "cc";
            c -= 2;
          } else {
            s += 'c';
            --c;
          }
        }
      } else if (s.back() == 'b') {
        if (a >= c) {
          if (a == 0) break;
          if (a >= 2 && a + c >= b) {
            s += "aa";
            a -= 2;
          } else {
            s += 'a';
            --a;
          }
        } else {
          if (c == 0) break;
          if (c >= 2 && a + c >= b) {
            s += "cc";
            c -= 2;
          } else {
            s += 'c';
            --c;
          }
        }
      } else {
        if (a >= b) {
          if (a == 0) break;
          if (a >= 2 && a + b >= c) {
            s += "aa";
            a -= 2;
          } else {
            s += 'a';
            --a;
          }
        } else {
          if (b == 0) break;
          if (b >= 2 && a + b >= c) {
            s += "bb";
            b -= 2;
          } else {
            s += 'b';
            --b;
          }
        }
      }
    }

    return s;
  }
};
