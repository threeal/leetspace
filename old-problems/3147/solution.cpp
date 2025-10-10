#include <limits>
#include <vector>

class Solution {
 public:
  int maximumEnergy(std::vector<int>& energy, int k) {
    int maxEnergy{std::numeric_limits<int>::min()};
    for (std::size_t i{energy.size() - k}; i < energy.size(); ++i) {
      if (energy[i] > maxEnergy) maxEnergy = energy[i];
    }

    for (std::size_t i{energy.size() - k}; i > 0; --i) {
      energy[i - 1] += energy[i + k - 1];
      if (energy[i - 1] > maxEnergy) maxEnergy = energy[i - 1];
    }

    return maxEnergy;
  }
};
