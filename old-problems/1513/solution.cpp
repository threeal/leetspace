#include <string>

class Solution {
 public:
  int numSub(std::string s) {
    long long num{0}, ones{0};
    for (const char c : s) {
      if (c == '0') {
        num = (num + (ones * (ones + 1)) / 2) % 1000000007;
        ones = 0;
      } else {
        ++ones;
      }
    }
    return (num + (ones * (ones + 1)) / 2) % 1000000007;
  }
};
