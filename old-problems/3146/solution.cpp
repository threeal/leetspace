#include <string>

class Solution {
 public:
  int findPermutationDifference(std::string s, std::string t) {
    std::size_t indices[26]{};
    for (std::size_t i{0}; i < s.size(); ++i) {
      indices[s[i] - 'a'] = i;
    }

    int diff{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      const std::size_t index{indices[t[i] - 'a']};
      diff += i >= index ? i - index : index - i;
    }

    return diff;
  }
};
