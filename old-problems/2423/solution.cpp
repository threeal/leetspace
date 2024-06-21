#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  bool equalFrequency(std::string word) {
    std::vector<std::uint8_t> frequencies(26, 0);
    for (const auto c : word) ++frequencies[c - 'a'];

    std::sort(frequencies.begin(), frequencies.end());
    for (int i = 0; i < 25; ++i) {
      switch (frequencies[i]) {
        case 0:
          continue;

        case 1:
          if (frequencies[25] == 1) return true;
          if (frequencies[i + 1] == frequencies[25]) return true;
      }

      return frequencies[i] == frequencies[24] &&
          frequencies[i] + 1 == frequencies[25];
    }

    return true;
  }
};
