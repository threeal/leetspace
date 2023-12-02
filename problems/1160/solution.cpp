#include <string>
#include <vector>

class Solution {
 public:
  int countCharacters(std::vector<std::string>& words, std::string chars) {
    std::vector<unsigned char> charCounts(26, 0);

    for (const auto c : chars) {
      ++charCounts[c - 'a'];
    }

    int sum = 0;
    for (const auto& word : words) {
      std::vector<unsigned char> wordCounts(26, 0);

      bool isGood = true;
      for (const auto c : word) {
        if (++wordCounts[c - 'a'] > charCounts[c - 'a']) {
          isGood = false;
          break;
        }
      }

      if (isGood) {
        for (const auto count : wordCounts) {
          sum += count;
        }
      }
    }

    return sum;
  }
};
