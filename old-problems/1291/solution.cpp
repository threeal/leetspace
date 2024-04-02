#include <cstdint>
#include <vector>

const int digits[36] = {
    12,
    23,
    34,
    45,
    56,
    67,
    78,
    89,
    123,
    234,
    345,
    456,
    567,
    678,
    789,
    1234,
    2345,
    3456,
    4567,
    5678,
    6789,
    12345,
    23456,
    34567,
    45678,
    56789,
    123456,
    234567,
    345678,
    456789,
    1234567,
    2345678,
    3456789,
    12345678,
    23456789,
    123456789};

class Solution {
 public:
  std::vector<int> sequentialDigits(int low, int high) {
    std::uint8_t i = 0;
    while (i < 36) {
      if (digits[i] >= low) break;
      ++i;
    }

    std::vector<int> output;
    while (i < 36 && digits[i] <= high) {
      output.push_back(digits[i]);
      ++i;
    }

    return output;
  }
};
