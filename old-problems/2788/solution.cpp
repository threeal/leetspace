#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> splitWordsBySeparator(
      std::vector<std::string>& words, char separator) {
    std::vector<std::string> output{};
    for (const std::string& word : words) {
      std::size_t l{0};
      for (std::size_t r{0}; r < word.size(); ++r) {
        if (word[r] == separator) {
          if (r - l > 0) output.push_back(word.substr(l, r - l));
          l = r + 1;
        }
      }
      if (word.size() - l > 0) output.push_back(word.substr(l));
    }
    return output;
  }
};
