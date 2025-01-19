#include <string>
#include <vector>

class Solution {
 public:
  int countPrefixSuffixPairs(std::vector<std::string>& words) {
    int count{0};
    for (std::size_t i{0}; i < words.size(); ++i) {
      const auto n = words[i].size();
      for (std::size_t j{i + 1}; j < words.size(); ++j) {
        if (n > words[j].size()) continue;
        if (words[j].compare(0, n, words[i]) != 0) continue;
        if (words[j].compare(words[j].size() - n, n, words[i]) != 0) continue;
        ++count;
      }
    }
    return count;
  }
};
