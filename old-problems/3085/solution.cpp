#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minimumDeletions(std::string word, int k) {
    std::vector<int> freqs(26, 0);
    for (const char c : word) ++freqs[c - 'a'];

    std::sort(freqs.begin(), freqs.end(), std::greater<int>());

    int l{0}, sum{0}, maxInclude{0};
    for (int r{0}; r < 26 && freqs[r] != 0; ++r) {
      sum += freqs[r];
      while (freqs[l] > freqs[r] + k) {
        sum -= freqs[l];
        ++l;
      }
      const int include{sum + l * (freqs[r] + k)};
      if (include > maxInclude) maxInclude = include;
    }

    return word.size() - maxInclude;
  }
};
