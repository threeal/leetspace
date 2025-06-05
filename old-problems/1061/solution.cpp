#include <string>

class Solution {
 public:
  std::string smallestEquivalentString(
      std::string s1, std::string s2, std::string baseStr) {
    int map[26]{};
    for (int i{0}; i < 26; ++i) map[i] = i;

    for (std::size_t i{0}; i < s1.size(); ++i) {
      int c1{s1[i] - 'a'};
      while (map[c1] != c1) c1 = map[c1];

      int c2{s2[i] - 'a'};
      while (map[c2] != c2) c2 = map[c2];

      if (c1 != c2) {
        if (c1 < c2) {
          map[c2] = c1;
        } else {
          map[c1] = c2;
        }
      }
    }

    for (std::size_t i{0}; i < baseStr.size(); ++i) {
      int c{baseStr[i] - 'a'};
      while (map[c] != c) c = map[c];

      baseStr[i] = 'a' + c;
    }

    return baseStr;
  }
};
