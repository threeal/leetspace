#include <vector>

class Solution {
 public:
  std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> output{};
    for (int num{left}; num <= right; ++num) {
      bool valid{true};
      for (int exp{1}; exp <= num; exp *= 10) {
        const int digit{num / exp % 10};
        if (digit == 0 || num % digit != 0) {
          valid = false;
          break;
        }
      }
      if (valid) output.push_back(num);
    }
    return output;
  }
};
