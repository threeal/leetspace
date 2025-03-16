#include <vector>

class Solution {
 public:
  long long repairCars(std::vector<int>& ranks, int cars) {
    return ranks.size() * cars;
  }
};
