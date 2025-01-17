#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> uncommonFromSentences(
      std::string s1, std::string s2) {
    std::unordered_map<std::string, int> freqs{};

    std::size_t start{0};
    for (std::size_t end{1}; end < s1.size(); ++end) {
      if (s1[end] == ' ') {
        ++freqs[s1.substr(start, end - start)];
        start = end + 1;
        ++end;
      }
    }
    ++freqs[s1.substr(start, s1.size() - start)];

    start = 0;
    for (std::size_t end{1}; end < s2.size(); ++end) {
      if (s2[end] == ' ') {
        ++freqs[s2.substr(start, end - start)];
        start = end + 1;
        ++end;
      }
    }
    ++freqs[s2.substr(start, s2.size() - start)];

    std::vector<std::string> output{};
    for (const auto& [s, freq] : freqs) {
      if (freq == 1) output.push_back(s);
    }

    // TODO: sort to pass test case.
    std::sort(output.begin(), output.end());

    return output;
  }
};
