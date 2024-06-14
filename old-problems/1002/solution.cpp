#include <algorithm>
#include <cstdint>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> commonChars(std::vector<std::string>& words) {
    std::vector<std::int8_t> allCounts(26, std::numeric_limits<std::int8_t>::max());
    std::vector<std::int8_t> counts(26, 0);

    for (const auto& word : words) {
      std::fill(counts.begin(), counts.end(), 0);
      for (const auto c : word) {
        ++counts[c - 'a'];
      }

      for (std::int8_t i{25}; i >= 0; --i) {
        if (allCounts[i] > counts[i]) allCounts[i] = counts[i];
      }
    }

    std::vector<std::string> chars(std::accumulate(allCounts.begin(), allCounts.end(), 0), "a");
    auto it = chars.rbegin();
    for (std::int8_t i{25}; i >= 0; --i) {
      while (allCounts[i] > 0) {
        --allCounts[i];
        (*it)[0] += i;
        ++it;
      }
    }

    return chars;
  }
};
