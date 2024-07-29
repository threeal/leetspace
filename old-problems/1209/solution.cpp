#include <cstring>
#include <string>
#include <vector>

class Solution {
 public:
  std::string removeDuplicates(std::string s, int k) {
    std::vector<int> freqs(s.size());

    std::size_t out{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      while (
          out > 0 && i < s.size() &&
          s[out - 1] == s[i] && freqs[out - 1] + 1 >= k) {
        --out;
        ++i;
      }
      if (i < s.size()) {
        if (out > 0 && s[out - 1] == s[i]) {
          ++freqs[out - 1];
        } else {
          s[out] = s[i];
          freqs[out] = 1;
          ++out;
        }
      }
    }

    int pos{0};
    for (int i = out - 1; i >= 0; --i) {
      pos += freqs[i];
    }

    s = s.substr(0, pos);
    for (int i = out - 1; i >= 0; --i) {
      pos -= freqs[i];
      std::memset(s.data() + pos, s[i], freqs[i] * sizeof(char));
    }

    return s;
  }
};
