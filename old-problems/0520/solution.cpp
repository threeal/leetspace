#include <string>

class Solution {
 public:
  bool detectCapitalUse(std::string word) {
    if (word[0] >= 'a') {
      for (std::size_t i{1}; i < word.size(); ++i) {
        if (word[i] < 'a') return false;
      }
    } else if (word.size() > 1) {
      if (word[1] >= 'a') {
        for (std::size_t i{2}; i < word.size(); ++i) {
          if (word[i] < 'a') return false;
        }
      } else {
        for (std::size_t i{2}; i < word.size(); ++i) {
          if (word[i] >= 'a') return false;
        }
      }
    }
    return true;
  }
};
