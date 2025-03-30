#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> partitionLabels(std::string s) {
    int allFreqs[26]{0};
    for (const auto c : s) ++allFreqs[c - 'a'];

    int freqs[26]{0};
    int missing{0};

    std::vector<int> output{};
    for (std::size_t l{0}, r{0}; r < s.size(); ++r) {
      ++freqs[s[r] - 'a'];
      if (freqs[s[r] - 'a'] == allFreqs[s[r] - 'a']) {
        if (freqs[s[r] - 'a'] != 1) --missing;
      } else {
        if (freqs[s[r] - 'a'] == 1) ++missing;
      }

      if (missing == 0) {
        output.push_back(r - l + 1);
        l = r + 1;
      }
    }

    return output;
  }
};
