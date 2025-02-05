#include <string>

class Solution {
 public:
  bool areAlmostEqual(std::string s1, std::string s2) {
    for (std::size_t i{0}; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) continue;
      for (std::size_t j{i + 1}; j < s1.size(); ++j) {
        if (s1[j] == s2[j]) continue;
        if (s1[i] != s2[j] || s1[j] != s2[i]) return false;
        for (++j; j < s1.size(); ++j) {
          if (s1[j] != s2[j]) return false;
        }
        return true;
      }
      return false;
    }
    return true;
  }
};
