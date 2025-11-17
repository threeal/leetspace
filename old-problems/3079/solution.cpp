#include <vector>

class Solution {
 public:
  int sumOfEncryptedInt(std::vector<int>& nums) {
    int sum{0};
    for (int num : nums) {
      int digits{0};
      int maxDigit{0};
      while (num > 0) {
        if (num % 10 > maxDigit) maxDigit = num % 10;
        num /= 10;
        ++digits;
      }

      int encrypted{0};
      while (digits > 0) {
        encrypted = encrypted * 10 + maxDigit;
        --digits;
      }

      sum += encrypted;
    }

    return sum;
  }
};
