#include <algorithm>
#include <limits>
#include <string>

class Solution {
 public:
  int maxDifference(std::string s) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    int even{std::numeric_limits<int>::max()};
    int odd{std::numeric_limits<int>::min()};

    for (int i{0}; i < 26; ++i) {
      if (freqs[i] > 0) {
        if (freqs[i] % 2 == 0) {
          if (freqs[i] < even) even = freqs[i];
        } else {
          if (freqs[i] > odd) odd = freqs[i];
        }
      }
    }

    return odd - even;
  }
};
