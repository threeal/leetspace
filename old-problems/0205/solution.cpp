#include <string>
#include <vector>

class Solution {
 public:
  bool isIsomorphic(std::string s, std::string t) {
    std::vector<std::size_t> sMap(128, 0);
    std::vector<std::size_t> tMap(128, 0);

    for (std::size_t i{0}; i < s.size(); ++i) {
      if (sMap[s[i]] != tMap[t[i]]) return false;
      sMap[s[i]] = i + 1;
      tMap[t[i]] = i + 1;
    }

    return true;
  }
};
