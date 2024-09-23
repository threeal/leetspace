#include <string>
#include <vector>

class Solution {
 public:
  int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
    std::vector<int> extraChars(s.size(), s.size());
    for (std::size_t r{0}; r < s.size(); ++r) {
      extraChars[r] = r > 0 ? extraChars[r - 1] + 1 : 1;
      for (const auto& word : dictionary) {
        if (r + 1 < word.size()) continue;
        if (s.compare(r + 1 - word.size(), word.size(), word) == 0) {
          if (r >= word.size()) {
            if (extraChars[r - word.size()] < extraChars[r]) {
              extraChars[r] = extraChars[r - word.size()];
            }
          } else {
            extraChars[r] = 0;
          }
        }
      }
    }
    return extraChars.back();
  }
};
