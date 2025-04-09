#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool hasGroupsSizeX(std::vector<int>& deck) {
    std::sort(deck.begin(), deck.end());

    std::size_t n{1};
    while (n < deck.size() && deck[n - 1] == deck[n]) ++n;
    if (n == 1) return false;

    std::size_t r{n};
    while (r < deck.size()) {
      const std::size_t l{r};
      ++r;

      while (r < deck.size() && deck[r - 1] == deck[r]) ++r;

      n = std::gcd(n, r - l);
      if (n == 1) return false;
    }

    return true;
  }
};
