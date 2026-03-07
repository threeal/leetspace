#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> toggleLightBulbs(std::vector<int>& bulbs) {
    std::sort(bulbs.begin(), bulbs.end());

    std::size_t n{0}, freqs{1};
    for (std::size_t i{1}; i < bulbs.size(); ++i) {
      if (bulbs[i] == bulbs[i - 1]) {
        ++freqs;
      } else {
        if (freqs % 2 == 1) bulbs[n++] = bulbs[i - 1];
        freqs = 1;
      }
    }

    if (freqs % 2 == 1) bulbs[n++] = bulbs.back();

    bulbs.resize(n);
    return bulbs;
  }
};
