#include <string>

class Solution {
 public:
  bool areOccurrencesEqual(std::string s) {
    char freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    for (int i{0}; i < 26; ++i) {
      if (freqs[i] != 0) {
        const int freq{freqs[i]};
        for (int j{i + 1}; j < 26; ++j) {
          if (freqs[j] != 0 && freqs[j] != freq) return false;
        }
        return true;
      }
    }

    return true;
  }
};
