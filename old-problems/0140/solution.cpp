#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::vector<std::string> output;
    std::unordered_set<std::string_view> wordSet(wordDict.begin(), wordDict.end());
    wordBreak(output, s, s.size(), wordSet);
    return output;
  }

  void wordBreak(std::vector<std::string>& output, std::string_view s, std::size_t n, const std::unordered_set<std::string_view>& wordSet) {
    for (auto i{n - 1}; i > 0; --i) {
      const auto substr{s.substr(i, n - i)};
      if (wordSet.contains(substr)) {
        auto prevSize{output.size()};
        wordBreak(output, s, i, wordSet);
        while (prevSize < output.size()) {
          output[prevSize] += " ";
          output[prevSize] += substr;
          ++prevSize;
        }
      }
    }

    const auto substr{s.substr(0, n)};
    if (wordSet.contains(s.substr(0, n))) {
      output.push_back({substr.begin(), substr.end()});
    }
  }
};
