#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> stringMatching(std::vector<std::string>& words) {
    std::vector<std::string> output{};
    for (const auto& word : words) {
      for (const auto& other_word : words) {
        if (word != other_word && other_word.find(word) != std::string::npos) {
          output.push_back(word);
          break;
        }
      }
    }
    return output;
  }
};
