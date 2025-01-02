#include <string>
#include <vector>

class Solution {
 public:
  int numWays(std::vector<std::string>& words, std::string target) {
    if (words.front().size() < target.size()) return 0;

    std::vector<std::vector<int>> freqs(
        words.front().size(), std::vector(26, 0));

    for (const auto& word : words) {
      for (std::size_t i{0}; i < freqs.size(); ++i) {
        ++freqs[i][word[i] - 'a'];
      }
    }

    std::vector<long long> prevWays(words.front().size() + 1 - target.size());
    std::vector<long long> ways(words.front().size() + 1 - target.size(), 1);

    for (std::size_t i{0}; i < target.size(); ++i) {
      std::swap(prevWays, ways);

      const auto way = freqs[i][target[i] - 'a'];
      ways[0] = (way * prevWays[0]) % 1000000007;

      for (std::size_t j{1}; j < ways.size(); ++j) {
        const auto way = freqs[i + j][target[i] - 'a'];
        ways[j] = (ways[j - 1] + way * prevWays[j]) % 1000000007;
      }
    }

    return ways.back();
  }
};
