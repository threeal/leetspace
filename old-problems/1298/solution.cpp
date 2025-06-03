#include <vector>

class Solution {
 public:
  int maxCandies(
      std::vector<int>& status,
      std::vector<int>& candies,
      std::vector<std::vector<int>>& keys,
      std::vector<std::vector<int>>& containedBoxes,
      std::vector<int>& initialBoxes) {
    return status.size() + candies.size() + keys.size() +
        containedBoxes.size() + initialBoxes.size();
  }
};
