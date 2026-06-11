#include <string>

class Solution {
 public:
  bool checkStrings(std::string s1, std::string s2) {
    int freqs[26]{0};
    for (std::size_t i{0}; i < 2; ++i) {
      for (std::size_t j{i}; j < s1.size(); j += 2) {
        ++freqs[s1[j] - 'a'];
        --freqs[s2[j] - 'a'];
      }

      for (int j{0}; j < 26; ++j) {
        if (freqs[j] != 0) return false;
      }
    }
    return true;
  }
};
