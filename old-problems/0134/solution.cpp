#include <vector>

class Solution {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    return gas.size() + cost.size();
  }
};
