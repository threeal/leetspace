#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  bool closeStrings(std::string word1, std::string word2) {
    std::vector<int> word1Counts(26, 0);
    for (const auto c : word1) {
      ++word1Counts[c - 'a'];
    }

    std::vector<int> word2Counts(26, 0);
    for (const auto c : word2) {
      ++word2Counts[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if ((word1Counts[i] > 0) != (word2Counts[i] > 0))
        return false;
    }

    sort(word1Counts.begin(), word1Counts.end());
    sort(word2Counts.begin(), word2Counts.end());

    return word1Counts == word2Counts;
  }
};
