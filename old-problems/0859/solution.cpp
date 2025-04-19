#include <string>

class Solution {
 public:
  bool buddyStrings(std::string s, std::string goal) {
    if (s.size() != goal.size()) return false;

    int freqs[26]{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == goal[i]) {
        ++freqs[s[i] - 'a'];
        continue;
      }

      for (std::size_t j{i + 1}; j < s.size(); ++j) {
        if (s[j] == goal[j]) continue;
        if (s[i] != goal[j] || s[j] != goal[i]) return false;
        for (std::size_t k{j + 1}; k < s.size(); ++k) {
          if (s[k] != goal[k]) return false;
        }
        return true;
      }
      return false;
    }

    for (int i{0}; i < 26; ++i) {
      if (freqs[i] >= 2) return true;
    }

    return false;
  }
};
