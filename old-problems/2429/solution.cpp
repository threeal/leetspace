#include <bit>

class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int n1{std::popcount<unsigned int>(num1)};
    int n2{std::popcount<unsigned int>(num2)};

    if (n1 < n2) {
      for (int b{1}, i{n1}; i < n2; ++i) {
        while ((num1 & b) != 0) b = b << 1;
        num1 |= b;
      }
    } else if (n1 > n2) {
      for (int b{1}, i{n2}; i < n1; ++i) {
        while ((num1 & b) == 0) b = b << 1;
        num1 ^= b;
      }
    }

    return num1;
  }
};
