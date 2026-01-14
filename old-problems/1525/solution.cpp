#include <string>

class Solution {
 public:
  int numSplits(std::string s) {
    int rFreqs[26]{0}, rDistinct{0};
    for (char c : s) {
      if (++rFreqs[c - 'a'] == 1) ++rDistinct;
    }

    int lFreqs[26]{0}, lDistinct{0}, splits{0};
    for (char c : s) {
      if (++lFreqs[c - 'a'] == 1) ++lDistinct;
      if (--rFreqs[c - 'a'] == 0) --rDistinct;
      if (lDistinct == rDistinct) ++splits;
    }

    return splits;
  }
};
