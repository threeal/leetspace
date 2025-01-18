#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> vowelStrings(
      std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
    std::vector<int> prefixCounts{};
    prefixCounts.reserve(words.size() + 1);
    prefixCounts.push_back(0);

    int count{0};
    for (const auto& word : words) {
      switch (word.front()) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          switch (word.back()) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
              ++count;
          }
      }
      prefixCounts.push_back(count);
    }

    std::vector<int> output{};
    output.reserve(queries.size());

    for (const auto& query : queries) {
      output.push_back(prefixCounts[query[1] + 1] - prefixCounts[query[0]]);
    }

    return output;
  }
};
