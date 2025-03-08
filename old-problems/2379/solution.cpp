#include <string>

class Solution {
 public:
  int minimumRecolors(std::string blocks, int k) {
    int freq{0};
    for (int i{0}; i < k; ++i) {
      if (blocks[i] == 'W') ++freq;
    }

    int minFreq{freq};
    for (std::size_t i = k; i < blocks.size(); ++i) {
      if (blocks[i] == 'W') ++freq;
      if (blocks[i - k] == 'W') --freq;
      if (freq < minFreq) minFreq = freq;
    }

    return minFreq;
  }
};
