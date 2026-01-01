#include <string>

class Solution {
 public:
  bool checkIfCanBreak(std::string s1, std::string s2) {
    int freqs1[26]{0}, freqs2[26]{0};
    for (std::size_t i{0}; i < s1.size(); ++i) {
      ++freqs1[s1[i] - 'a'];
      ++freqs2[s2[i] - 'a'];
    }

    int diff{0};
    for (int i{0}; i < 26; ++i) {
      diff += freqs1[i] - freqs2[i];
      if (diff < 0) {
        diff = 0;
        for (int j{0}; j < 26; ++j) {
          diff += freqs2[j] - freqs1[j];
          if (diff < 0) return false;
        }
        return true;
      }
    }

    return true;
  }
};
