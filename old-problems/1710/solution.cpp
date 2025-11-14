#include <vector>

class Solution {
 public:
  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    return boxTypes.size() + truckSize;
  }
};
