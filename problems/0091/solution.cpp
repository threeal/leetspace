#include <string>

class Solution {
 public:
  int numDecodings(std::string s) {
    int prev_ways = 0;
    int ways = 1;

    s += '9';
    for (int i = s.size() - 2; i >= 0; --i) {
      const int temp_ways = ways;
      switch (s[i]) {
        case '0':
          ways = 0;
          break;

        case '1':
          ways += prev_ways;
          break;

        case '2':
          if (s[i + 1] <= '6') ways += prev_ways;
          break;
      }
      prev_ways = temp_ways;
    }

    return ways;
  }
};
