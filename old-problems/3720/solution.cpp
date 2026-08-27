#include <string>

class Solution {
 public:
  std::string lexGreaterPermutation(std::string s, std::string target) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    std::size_t i{0};
    while (i < target.size() && freqs[target[i] - 'a'] != 0) {
      --freqs[target[i] - 'a'];
      s[i] = target[i];
      ++i;
    }

    if (i == target.size()) {
      --i;
      ++freqs[target[i] - 'a'];
    }

    while (true) {
      int c{target[i] - 'a' + 1};
      while (c < 26 && freqs[c] == 0) ++c;
      if (c < 26) {
        s[i] = 'a' + c;
        --freqs[c];
        ++i;
        break;
      }

      if (i == 0) return "";

      --i;
      ++freqs[target[i] - 'a'];
    }

    int c{0};
    while (i < target.size()) {
      while (freqs[c] == 0) ++c;
      s[i] = 'a' + c;
      --freqs[c];
      ++i;
    }

    return s;
  }
};
