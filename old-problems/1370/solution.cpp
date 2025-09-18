#include <string>

class Solution {
 public:
  std::string sortString(std::string s) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    for (std::size_t i{0}; i < s.size();) {
      for (int j{0}; j < 26; ++j) {
        if (freqs[j] > 0) {
          s[i++] = 'a' + j;
          --freqs[j];
        }
      }

      for (int j{25}; j >= 0; --j) {
        if (freqs[j] > 0) {
          s[i++] = 'a' + j;
          --freqs[j];
        }
      }
    }

    return s;
  }
};
