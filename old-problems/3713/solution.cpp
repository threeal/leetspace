#include <string>

class Solution {
 public:
  int longestBalanced(std::string s) {
    for (char& c : s) c -= 'a';

    std::size_t maxLength{0};
    for (std::size_t l{0}; l < s.size(); ++l) {
      int freqs[26]{0};
      int maxFreqs{0}, maxFreqsCount{0}, count{0};
      for (std::size_t r{l}; r < s.size(); ++r) {
        ++freqs[s[r]];
        if (freqs[s[r]] == 1) ++count;
        if (freqs[s[r]] == maxFreqs) {
          ++maxFreqsCount;
        } else if (freqs[s[r]] > maxFreqs) {
          maxFreqs = freqs[s[r]];
          maxFreqsCount = 1;
        }

        if (maxFreqsCount == count && r + 1 - l > maxLength) {
          maxLength = r + 1 - l;
        }
      }
    }

    return maxLength;
  }
};
