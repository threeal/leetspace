#include <vector>

class Solution {
 public:
  int countTestedDevices(std::vector<int>& batteryPercentages) {
    int count{0};
    for (const int battery : batteryPercentages) {
      if (battery > count) ++count;
    }
    return count;
  }
};
