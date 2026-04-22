#include <bit>
#include <string>

class Solution {
 public:
  int residuePrefixes(std::string s) {
    int count{0};
    std::uint32_t distincts{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      distincts |= 1 << (s[i] - 'a');
      if (std::popcount(distincts) == (i + 1) % 3) ++count;
    }
    return count;
  }
};
