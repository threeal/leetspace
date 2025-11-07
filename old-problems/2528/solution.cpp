#include <vector>

class Solution {
 public:
  long long maxPower(std::vector<int>& stations, int r, int k) {
    return stations.size() + r + k;
  }
};
