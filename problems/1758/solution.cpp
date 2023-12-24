#include <algorithm>
#include <string>

class Solution {
 public:
  int minOperations(std::string s) {
    int cost01 = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      if (s[i] - '0' != i % 2) {
        ++cost01;
      }
    }

    const int cost10 = s.size() - cost01;
    return std::min(cost01, cost10);
  }
};
