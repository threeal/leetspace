#include <algorithm>
#include <vector>

class Solution {
 public:
  int numRescueBoats(std::vector<int>& people, int limit) {
    int boats{0};

    std::sort(people.begin(), people.end());

    std::size_t low{0};
    std::size_t high{people.size() - 1};

    while (low < high) {
      ++boats;
      if (people[low] + people[high] <= limit) {
        ++low;
        --high;
      } else {
        --high;
      }
    }

    if (low == high) ++boats;

    return boats;
  }
};
