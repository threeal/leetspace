#include <vector>

class Solution {
 public:
  int countTestedDevices(std::vector<int>& batteryPercentages) {
    return batteryPercentages.front();
  }
};
