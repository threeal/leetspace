#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maximumTotalDamage(std::vector<int>& power) {
    std::sort(power.begin(), power.end());

    long long tot{power[0]}, tot1{0}, tot2{0}, temp{};
    for (std::size_t i{1}; i < power.size(); ++i) {
      switch (power[i] - power[i - 1]) {
        case 0:
          tot += power[i];
          break;

        case 1:
          temp = tot2 + power[i];
          tot2 = std::max(tot2, tot1);
          tot1 = std::max(tot1, tot);
          tot = temp;
          break;

        case 2:
          temp = std::max(tot1, tot2) + power[i];
          tot1 = tot2 = std::max(tot, std::max(tot1, tot2));
          tot = temp;
          break;

        default:
          tot = tot1 = tot2 = std::max(tot, std::max(tot1, tot2));
          tot += power[i];
      }
    }

    return std::max(tot, std::max(tot1, tot2));
  }
};
