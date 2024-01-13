#include <string>
#include <vector>

class Solution {
 public:
  int minSteps(std::string s, std::string t) {
    std::vector<int> counts(26, 0);

    for (const auto c : s) {
      ++counts[c - 'a'];
    }

    for (const auto c : t) {
      --counts[c - 'a'];
    }

    int diff = 0;
    for (const auto count : counts) {
      diff += std::abs(count);
    }

    return diff / 2;
  }
};
