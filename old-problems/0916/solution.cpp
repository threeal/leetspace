#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> wordSubsets(
      std::vector<std::string>& words1, std::vector<std::string>& words2) {
    int maxFreqs[26] = {0};
    for (const auto& word : words2) {
      int freqs[26] = {0};
      for (const auto c : word) ++freqs[c - 'a'];

      for (int i{0}; i < 26; ++i) {
        if (freqs[i] > maxFreqs[i]) maxFreqs[i] = freqs[i];
      }
    }

    std::vector<std::string> output{};
    for (const auto& word : words1) {
      int freqs[26] = {0};
      for (const auto c : word) ++freqs[c - 'a'];

      int i{0};
      while (i < 26) {
        if (freqs[i] < maxFreqs[i]) break;
        ++i;
      }

      if (i == 26) output.push_back(word);
    }

    return output;
  }
};
