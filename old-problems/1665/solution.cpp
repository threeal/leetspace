#include <vector>

class Solution {
 public:
  int minimumEffort(std::vector<std::vector<int>>& tasks) {
    std::sort(
        tasks.begin(), tasks.end(),
        [](const auto& a, const auto& b) {
          return a[1] - a[0] > b[1] - b[0];
        });

    int energy{0}, effort{0};
    for (const auto& task : tasks) {
      if (energy < task[1]) {
        effort += task[1] - energy;
        energy = task[1];
      }
      energy -= task[0];
    }

    return effort;
  }
};
