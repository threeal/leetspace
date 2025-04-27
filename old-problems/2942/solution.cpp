#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findWordsContaining(
      std::vector<std::string>& words, char x) {
    std::vector<int> output{};
    output.reserve(words.size());
    for (std::size_t i{0}; i < words.size(); ++i) {
      for (const char c : words[i]) {
        if (c == x) {
          output.push_back(i);
          break;
        }
      }
    }
    return output;
  }
};
