#include <array>

static constexpr std::array<std::array<char, 10>, 32> generateTwoDigits() {
  std::array<std::array<char, 10>, 32> digits{};
  for (int i{0}; i < 32; ++i) {
    unsigned int n{1u << i};
    while (n != 0) {
      ++digits[i][n % 10];
      n /= 10;
    }
  }
  return digits;
}

class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    constexpr std::array<std::array<char, 10>, 32> twoDigits{
        generateTwoDigits()};

    std::array<char, 10> digits{0};
    while (n != 0) {
      ++digits[n % 10];
      n /= 10;
    }

    for (int i{0}; i < 32; ++i) {
      int j{0};
      while (j < 10 && digits[j] == twoDigits[i][j]) ++j;
      if (j == 10) return true;
    }

    return false;
  }
};
