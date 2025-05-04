#include <vector>

class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {
    return hours.size() + target;
  }
};
