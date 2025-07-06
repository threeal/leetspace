#include <string>

class Solution {
 public:
  int maxFreqSum(std::string s) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];

    int vowels{0}, consonants{0};
    for (int i{0}; i < 26; ++i) {
      switch (i) {
        case 0:
        case 4:
        case 8:
        case 14:
        case 20:
          if (freqs[i] > vowels) vowels = freqs[i];
          break;

        default:
          if (freqs[i] > consonants) consonants = freqs[i];
      }
    }

    return vowels + consonants;
  }
};
