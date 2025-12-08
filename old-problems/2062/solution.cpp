#include <string>

class Solution {
 public:
  int countVowelSubstrings(std::string word) {
    std::size_t total{0};
    char n{0}, freqs[26]{0};
    for (std::size_t ll{0}, l{0}, r{0}; r < word.size(); ++r) {
      switch (word[r]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          if (++freqs[word[r] - 'a'] == 1) ++n;
          if (n == 5) {
            while (freqs[word[l] - 'a'] > 1) {
              --freqs[word[l] - 'a'];
              ++l;
            }
            total += l + 1 - ll;
          }
          break;

        default:
          n = 0;
          while (l <= r) {
            --freqs[word[l] - 'a'];
            ++l;
          }
          ll = l;
      }
    }
    return total;
  }
};
