#include <string>
#include <vector>

class Solution {
 public:
  int numDecodings(std::string s) {
    const int n = s.size();
    s += '9';

    std::vector<int> ways(n + 1, 0);
    ways[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
      switch (s[i]) {
        case '0':
          ways[i] = 0;
          break;

        case '1':
          ways[i] = ways[i + 1] + ways[i + 2];
          break;

        case '2':
          ways[i] = ways[i + 1];
          if (s[i + 1] <= '6') ways[i] += ways[i + 2];
          break;

        default:
          ways[i] = ways[i + 1];
      }
    }

    return ways[0];
  }
};
