#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  bool hasAllCodes(std::string s, int k) {
    if (s.size() < static_cast<std::size_t>(k)) return false;

    std::vector<bool> exists(1 << k, false);
    std::size_t existsCount{0};

    std::uint32_t mask{1};
    mask = (mask << k) - 1;

    std::uint32_t code{0};
    for (int i{0}; i < k; ++i) {
      code <<= 1;
      if (s[i] == '1') code |= 1;
    }

    exists[code & mask] = true;
    ++existsCount;

    for (std::size_t i = k; i < s.size(); ++i) {
      code <<= 1;
      if (s[i] == '1') code |= 1;
      if (!exists[code & mask]) {
        exists[code & mask] = true;
        if (++existsCount == exists.size()) return true;
      }
    }

    return false;
  }
};
