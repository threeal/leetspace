#include <string>

class Solution {
 public:
  bool checkInclusion(std::string s1, std::string s2) {
    int freqs1[26] = {0};
    for (const auto c : s1) ++freqs1[c - 'a'];

    int freqs2[26] = {0};
    for (std::size_t l{0}, r{0}; r < s2.size(); ++r) {
      const auto c = s2[r] - 'a';
      ++freqs2[c];
      while (l <= r && freqs2[c] > freqs1[c]) {
        --freqs2[s2[l] - 'a'];
        ++l;
      }
      if (r - l + 1 == s1.size()) return true;
    }

    return s1 == s2;
  }
};
