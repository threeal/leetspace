#include <string>

class Solution {
 public:
  std::string majorityFrequencyGroup(std::string s) {
    int freqs[26]{0};
    for (char c : s) ++freqs[c - 'a'];

    int freqMembers[101]{0};
    int majorFreq{0};
    for (int i{0}; i < 26; ++i) {
      if (freqs[i] != 0) {
        ++freqMembers[freqs[i]];
        if (freqMembers[freqs[i]] > freqMembers[majorFreq] ||
            (freqMembers[freqs[i]] == freqMembers[majorFreq] && freqs[i] > majorFreq)) {
          majorFreq = freqs[i];
        }
      }
    }

    s.clear();
    for (int i{0}; i < 26; ++i) {
      if (freqs[i] == majorFreq) s += 'a' + i;
    }

    return s;
  }
};
