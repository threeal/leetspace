#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findAndReplacePattern(
      std::vector<std::string>& words, std::string pattern) {
    words.push_back(pattern);
    return words;
  }
};
