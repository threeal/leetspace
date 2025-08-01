#include <queue>
#include <vector>

class Solution {
 public:
  int maxCandies(
      std::vector<int>& status,
      std::vector<int>& candies,
      std::vector<std::vector<int>>& keys,
      std::vector<std::vector<int>>& containedBoxes,
      std::vector<int>& initialBoxes) {
    std::queue<int> boxes{};
    for (const int box : initialBoxes) {
      if ((status[box] |= 2) == 3) {
        status[box] |= 4;
        boxes.push(box);
      }
    }

    int totalCandies{0};
    while (!boxes.empty()) {
      totalCandies += candies[boxes.front()];

      for (const int key : keys[boxes.front()]) {
        if ((status[key] |= 1) == 3) {
          status[key] |= 4;
          boxes.push(key);
        }
      }

      for (const int box : containedBoxes[boxes.front()]) {
        if ((status[box] |= 2) == 3) {
          status[box] |= 4;
          boxes.push(box);
        }
      }

      boxes.pop();
    }

    return totalCandies;
  }
};
