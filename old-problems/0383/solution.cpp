#include <string>

class Solution {
 public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    int freqs[26]{0};
    for (const auto c : ransomNote) ++freqs[c - 'a'];
    for (const auto c : magazine) --freqs[c - 'a'];

    for (int i{0}; i < 26; ++i) {
      if (freqs[i] > 0) return false;
    }

    return true;
  }
};
