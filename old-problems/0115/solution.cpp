#include <string>
#include <vector>

class Solution {
 public:
  int numDistinct(std::string s, std::string t) {
    if (t.size() > s.size()) return 0;

    std::size_t l{0}, r{s.size() - t.size() + 1};
    std::vector<long long> counts(r, 1);
    for (std::size_t k{0}; k < t.size(); ++k, ++l, ++r) {
      while (l < r && s[l] != t[k]) ++l;
      if (l == r) return 0;

      long long count{0};
      for (std::size_t i{l}; i < r; ++i) {
        if (s[i] == t[k]) count += counts[i - k];
        counts[i - k] = count;
      }
    }

    return counts.back();
  }
};
