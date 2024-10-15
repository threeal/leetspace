#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  int countWords(
      std::vector<std::string>& words1, std::vector<std::string>& words2) {
    if (words2.size() < words1.size()) std::swap(words1, words2);

    std::unordered_map<std::string, int> frequencies{};
    for (const auto& word : words1) ++frequencies[word];

    int count{0};
    for (const auto& word : words2) {
      auto it = frequencies.find(word);
      if (it != frequencies.end()) {
        if (it->second == 1) {
          ++count;
          --(it->second);
        } else if (it->second == 0) {
          --count;
          --(it->second);
        }
      }
    }

    return count;
  }
};
