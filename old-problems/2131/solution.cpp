#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int longestPalindrome(std::vector<std::string>& words) {
    std::unordered_map<std::string_view, int> freqs{};
    for (const auto& word : words) ++freqs[word];

    int count{0};
    bool hasMiddle{false};
    for (const auto& [word, freq] : freqs) {
      if (word[0] == word[1]) {
        count += (freq / 2) * 4;
        if (freq % 2 == 1) hasMiddle = true;
      } else if (word[0] < word[1]) {
        std::string rword{word};
        rword[0] = word[1];
        rword[1] = word[0];

        const auto it = freqs.find(rword);
        if (it != freqs.end()) {
          count += std::min(freq, it->second) * 4;
        }
      }
    }

    if (hasMiddle) count += 2;
    return count;
  }
};
