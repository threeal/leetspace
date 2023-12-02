// The solution can be done as follows:
// - Count each character in the `chars` string.
// - For each string in `words`, it is good if each character count
//   is equal to or less than the count in the `chars` string.
// - Return the total length of all good strings.

#include <string>
#include <vector>

class Solution {
 public:
  int countCharacters(std::vector<std::string>& words, std::string chars) {
    std::vector<int> charCounts(26, 0);

    // Count each character in the `chars` string.
    for (const auto c : chars) {
      ++charCounts[c - 'a'];
    }

    // Check if each string in `words` is good.
    int totalSum = 0;
    for (const auto& word : words) {
      bool isGood = true;

      // Copy the counting array and decrement it to check if the string is good.
      auto counts = charCounts;
      for (const auto c : word) {
        if (--counts[c - 'a'] < 0) {
          isGood = false;
          break;
        }
      }

      // Sum the length of the string if it is good.
      if (isGood) totalSum += word.size();
    }

    return totalSum;
  }
};
