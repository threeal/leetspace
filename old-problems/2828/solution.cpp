#include <string>
#include <vector>

class Solution {
 public:
  bool isAcronym(std::vector<std::string>& words, std::string s) {
    if (words.size() != s.size()) return false;

    for (std::size_t i{0}; i < words.size(); ++i) {
      if (words[i][0] != s[i]) return false;
    }

    return true;
  }
};
