#include <string>

class Solution {
 public:
  long long minimumSteps(std::string s) {
    long long sum{0}, ones{0};
    for (const auto c : s) {
      if (c == '1') {
        ++ones;
      } else {
        sum += ones;
      }
    }
    return sum;
  }
};
