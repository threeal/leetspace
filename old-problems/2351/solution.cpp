#include <string>

class Solution {
 public:
  char repeatedCharacter(std::string s) {
    std::uint32_t exists{0};
    for (const auto c : s) {
      if ((exists & 1 << (c - 'a')) != 0) return c;
      exists |= 1 << (c - 'a');
    }
    return 0;
  }
};
