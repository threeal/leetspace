#include <string>

class Solution {
 public:
  int maximumLengthSubstring(std::string s) {
    std::uint64_t freqs{0};
    std::size_t maxLen{0};
    for (std::size_t l{0}, r{0}; r < s.size(); ++r) {
      std::uint64_t flag{1llu << ((s[r] - 'a') * 2 + 1)};
      while ((freqs & flag) != 0) {
        freqs -= 1llu << ((s[l] - 'a') * 2);
        ++l;
      }
      freqs += 1llu << (s[r] - 'a') * 2;
      if (r + 1 - l > maxLen) maxLen = r + 1 - l;
    }
    return maxLen;
  }
};
