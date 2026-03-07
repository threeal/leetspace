#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minimumPushes(std::string word) {
    std::vector<int> freqs(26, 0);
    for (char c : word) ++freqs[c - 'a'];

    std::sort(freqs.begin(), freqs.end(), std::greater<int>());

    int sum{0};
    for (int i{0}; i < 26 && freqs[i] != 0; ++i) {
      sum += (i / 8 + 1) * freqs[i];
    }

    return sum;
  }
};
