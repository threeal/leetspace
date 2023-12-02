#include <string>
#include <vector>

class Solution {
 public:
  int countCharacters(std::vector<std::string>& words, std::string chars) {
    std::vector<int> charCounts(26, 0);

    for (const auto c : chars) {
      ++charCounts[c - 'a'];
    }

    int totalSum = 0;
    for (const auto& word : words) {
      bool isGood = true;
      auto counts = charCounts;
      for (const auto c : word) {
        if (--counts[c - 'a'] < 0) {
          isGood = false;
          break;
        }
      }

      if (isGood) totalSum += word.size();
    }

    return totalSum;
  }
};
