#include <string>

class Solution {
 public:
  int minimumLength(std::string s) {
    int freqs[26] = {0};
    for (const auto c : s) {
      ++freqs[c - 'a'];
    }

    int len{0};
    for (int i{0}; i < 26; ++i) {
      if (freqs[i] == 0) continue;
      len += freqs[i] % 2 == 0 ? 2 : 1;
    }

    return len;
  }
};
