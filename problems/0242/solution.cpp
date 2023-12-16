#include <string>
#include <vector>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::vector<int> counts('z' - 'a' + 1, 0);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }

    for (const auto c : t) {
      if (--counts[c - 'a'] < 0) return false;
    }

    return true;
  }
};
