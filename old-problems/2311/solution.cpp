#include <bit>
#include <string>

class Solution {
 public:
  int longestSubsequence(std::string s, int k) {
    unsigned long long num{0};
    int count{0}, maxCount{0};
    for (const char c : s) {
      ++count;
      num = num << 1 | (c == '0' ? 0 : 1);
      while (num > static_cast<unsigned long long>(k)) {
        num &= ~(1 << (63 - std::countl_zero<unsigned long long>(num)));
        --count;
      }
      if (count > maxCount) maxCount = count;
    }
    return maxCount;
  }
};
