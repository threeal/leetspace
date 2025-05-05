#include <vector>

class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {
    int count{0};
    for (const int hour : hours) {
      if (hour >= target) ++count;
    }
    return count;
  }
};
