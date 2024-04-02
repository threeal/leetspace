#include <string>
#include <vector>

class Solution {
 public:
  std::string firstPalindrome(std::vector<std::string>& words) {
    for (const auto& word : words) {
      int l = 0;
      int r = word.size() - 1;
      while (l < r && word[l] == word[r]) {
        ++l;
        --r;
      }
      if (l >= r) return word;
    }
    return "";
  }
};
