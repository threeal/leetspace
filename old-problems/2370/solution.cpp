#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

class Solution {
 public:
  int longestIdealString(std::string s, int k) {
    std::vector<int> counts(26, 0);
    for (const auto c : s) {
      const int i{c - 'a'};
      const int count{counts[i] + 1};

      const int n{std::min(25, i + k)};
      for (int j{std::max(0, i - k)}; j <= n; ++j) {
        if (count > counts[j]) counts[j] = count;
      }
    }

    return *std::max_element(counts.begin(), counts.end());
  }
};
