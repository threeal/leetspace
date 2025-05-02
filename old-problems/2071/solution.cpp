#include <algorithm>
#include <deque>
#include <vector>

class Solution {
 public:
  int maxTaskAssign(
      std::vector<int>& tasks, std::vector<int>& workers,
      int pills, int strength) {
    std::sort(tasks.begin(), tasks.end());
    std::sort(workers.begin(), workers.end());

    std::size_t low{0}, high{std::min(tasks.size(), workers.size())};
    while (low < high) {
      std::size_t mid{high - (high - low) / 2};

      bool isValid{true};

      int freePills{pills};
      std::deque<int> unassigned{};
      for (std::size_t i{0}, j{workers.size()}; i < mid; ++i) {
        const int task{tasks[mid - i - 1]};
        if (!unassigned.empty() && unassigned.front() >= task) {
          unassigned.pop_back();
        } else if (j > 0 && workers[j - 1] >= task) {
          --j;
        } else {
          while (j > 0 && workers[j - 1] + strength >= task) {
            unassigned.push_back(workers[--j]);
          }
          if (unassigned.empty() || freePills == 0) {
            isValid = false;
            break;
          }
          unassigned.pop_back();
          --freePills;
        }
      }

      if (isValid) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
