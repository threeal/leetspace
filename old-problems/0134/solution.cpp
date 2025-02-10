#include <vector>

class Solution {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int totalGas{0};
    for (std::size_t l{0}, n{0}; l < gas.size(); ++l, --n) {
      while (totalGas >= 0 && n < gas.size()) {
        totalGas += gas[(l + n) % gas.size()] - cost[(l + n) % gas.size()];
        ++n;
      }
      if (totalGas >= 0) return l;
      totalGas -= gas[l] - cost[l];
    }
    return -1;
  }
};
