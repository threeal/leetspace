#include <algorithm>
#include <string>

class Solution {
 public:
  std::string mergeAlternately(std::string word1, std::string word2) {
    std::string output{};
    output.reserve(word1.size() + word2.size());

    std::size_t n{std::min(word1.size(), word2.size())};
    for (std::size_t i{0}; i < n; ++i) {
      output.push_back(word1[i]);
      output.push_back(word2[i]);
    }

    for (std::size_t i{n}; i < word1.size(); ++i) output.push_back(word1[i]);
    for (std::size_t i{n}; i < word2.size(); ++i) output.push_back(word2[i]);

    return output;
  }
};
