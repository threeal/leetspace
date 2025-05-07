#include <vector>

class Solution {
 public:
  int largestAltitude(std::vector<int>& gains) {
    int maxAltitude{0}, altitude{0};
    for (const int gain : gains) {
      altitude += gain;
      if (altitude > maxAltitude) maxAltitude = altitude;
    }
    return maxAltitude;
  }
};
