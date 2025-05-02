#include <vector>

class Solution {
 public:
  int maxTaskAssign(
      std::vector<int>& tasks, std::vector<int>& workers,
      int pills, int strength) {
    return tasks.size() + workers.size() + pills + strength;
  }
};
