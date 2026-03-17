#include <cstdint>
#include <string>

class Solution {
 public:
  bool isSubstringPresent(std::string s) {
    std::uint32_t exists[26]{0};
    for (std::size_t i{1}; i < s.size(); ++i) {
      exists[s[i] - 'a'] |= 1 << (s[i - 1] - 'a');
    }

    for (std::size_t i{1}; i < s.size(); ++i) {
      if ((exists[s[i - 1] - 'a'] & (1 << (s[i] - 'a'))) != 0) return true;
    }

    return false;
  }
};
