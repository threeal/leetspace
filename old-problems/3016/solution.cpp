#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minimumPushes(std::string word) {
    std::vector freqs(26, 0);
    for (const auto c : word) ++freqs[c - 'a'];

    std::sort(freqs.begin(), freqs.end(), std::greater<int>());

    int pushes{0};
    for (int i = 0; i < 26 && freqs[i] > 0; ++i) {
      pushes += freqs[i] * (i / 8 + 1);
    }
    return pushes;
  }
};
