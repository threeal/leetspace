#include <map>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool hasGroupsSizeX(std::vector<int>& deck) {
    std::map<int, int> freqs{};
    for (const auto card : deck) ++freqs[card];

    int prevFreq{freqs.begin()->second};
    for (const auto [card, freq] : freqs) {
      const int gcd{std::gcd(prevFreq, freq)};
      if (gcd == 1) return false;
      if (gcd < prevFreq) prevFreq = gcd;
    }

    return true;
  }
};
