#include <algorithm>

class Solution {
 public:
  int generateKey(int num1, int num2, int num3) {
    int key{0};
    for (int exp{1}; exp <= 1000; exp *= 10) {
      key += std::min(std::min(num1 / exp % 10, num2 / exp % 10), num3 / exp % 10) * exp;
    }
    return key;
  }
};
