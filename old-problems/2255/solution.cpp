#include <string>
#include <vector>

class Solution {
 public:
  int countPrefixes(std::vector<std::string>& words, std::string s) {
    int count{0};
    for (const std::string& word : words) {
      if (word.size() <= s.size()) {
        bool valid{true};
        for (std::size_t i{0}; i < word.size(); ++i) {
          if (word[i] != s[i]) {
            valid = false;
            break;
          }
        }
        if (valid) ++count;
      }
    }
    return count;
  }
};
