#include <vector>

class Solution {
 public:
  int minimumEffort(std::vector<std::vector<int>>& tasks) {
    int low{0}, high{0};
    for (const auto& task : tasks) {
      low += task[0];
      high += task[1];
    }

    std::sort(
        tasks.begin(), tasks.end(),
        [](const auto& a, const auto& b) {
          const int aa{a[1] - a[0]};
          const int bb{b[1] - b[0]};
          return aa == bb ? a[1] > b[1] : aa > bb;
        });

    while (low < high) {
      const int mid{low + (high - low) / 2};

      int energy{mid};
      for (const auto& task : tasks) {
        if (task[1] > energy || task[0] > energy) {
          energy = -1;
          break;
        }
        energy -= task[0];
      }

      if (energy >= 0) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
