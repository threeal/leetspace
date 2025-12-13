#include <cstdlib>
#include <string>

class Solution {
 public:
  int minSteps(std::string s, std::string t) {
    int freqs[26]{0};
    for (const char c : s) ++freqs[c - 'a'];
    for (const char c : t) --freqs[c - 'a'];

    int steps{0};
    for (int i = 0; i < 26; ++i) steps += std::abs(freqs[i]);

    return steps;
  }
};
