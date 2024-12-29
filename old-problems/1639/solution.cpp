#include <string>
#include <vector>

class Solution {
 public:
  int numWays(std::vector<std::string>& words, std::string target) {
    if (words.front().size() < target.size()) return 0;

    std::vector<long long> prevWays(words.front().size() + 1 - target.size());
    std::vector<long long> ways(words.front().size() + 1 - target.size(), 1);

    for (std::size_t i{0}; i < target.size(); ++i) {
      std::swap(prevWays, ways);

      long long way{0};
      for (const auto& word : words) {
        if (word[i] == target[i]) ++way;
      }
      ways[0] = (way * prevWays[0]) % 1000000007;

      for (std::size_t j{1}; j < ways.size(); ++j) {
        long long way{0};
        for (const auto& word : words) {
          if (word[i + j] == target[i]) ++way;
        }
        ways[j] = (ways[j - 1] + way * prevWays[j]) % 1000000007;
      }
    }

    return ways.back();
  }
};
