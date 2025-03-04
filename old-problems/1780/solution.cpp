#include <iostream>

class Solution {
 public:
  bool checkPowersOfThree(int n) {
    for (int exp{4782969}; exp > 0; exp /= 3) {
      if (exp <= n) n -= exp;
    }
    return n == 0;
  }
};
