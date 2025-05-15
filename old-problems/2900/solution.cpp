#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> getLongestSubsequence(
      std::vector<std::string>& words, std::vector<int>& groups) {
    std::size_t n{1};
    int group{groups[0]};
    for (std::size_t i{1}; i < words.size(); ++i) {
      if (groups[i] != group) {
        group = groups[i];
        words[n++] = words[i];
      }
    }
    words.resize(n);
    return words;
  }
};
