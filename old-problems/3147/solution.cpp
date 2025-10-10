#include <vector>

class Solution {
 public:
  int maximumEnergy(std::vector<int>& energy, int k) {
    return energy.size() + k;
  }
};
