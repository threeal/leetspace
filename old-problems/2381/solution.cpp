#include <string>
#include <vector>

class Solution {
 public:
  std::string shiftingLetters(
      std::string s, std::vector<std::vector<int>>& shifts) {
    std::vector<int> prefixes(s.size() + 1, 0);
    for (const auto& shift : shifts) {
      if (shift[2] == 0) {
        --prefixes[shift[0]];
        ++prefixes[shift[1] + 1];
      } else {
        ++prefixes[shift[0]];
        --prefixes[shift[1] + 1];
      }
    }

    int shift = 0;
    for (std::size_t i{0}; i < s.size(); ++i) {
      shift = (shift + prefixes[i]) % 26;
      s[i] = 'a' + ((s[i] - 'a' + shift) % 26 + 26) % 26;
    }

    return s;
  }
};
