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
      int sum = 0;
      auto counts = charCounts;
      for (const auto c : word) {
        if (--counts[c - 'a'] < 0) {
          sum = 0;
          break;
        }
        ++sum;
      }

      totalSum += sum;
    }

    return totalSum;
  }
};
