#include <limits>
#include <vector>

class Solution {
 public:
  int earliestTime(std::vector<std::vector<int>>& tasks) {
    int earliest{std::numeric_limits<int>::max()};
    for (const auto& task : tasks) {
      if (task[0] + task[1] < earliest) {
        earliest = task[0] + task[1];
      }
    }
    return earliest;
  }
};
