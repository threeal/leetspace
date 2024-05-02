#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<int> lengths(text2.size() + 1, 0);
    auto prevLengths = lengths;

    for (const auto c : text1) {
      prevLengths = lengths;
      std::fill(lengths.begin(), lengths.end(), 0);

      for (std::size_t j{0}; j < text2.size(); ++j) {
        lengths[j + 1] = c == text2[j]
            ? 1 + prevLengths[j]
            : std::max(lengths[j], prevLengths[j + 1]);
      }
    }

    return lengths[text2.size()];
  }
};
