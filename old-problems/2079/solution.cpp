#include <vector>

class Solution {
 public:
  int wateringPlants(std::vector<int>& plants, int capacity) {
    int steps{0}, water{capacity};
    for (std::size_t i{0}; i < plants.size(); ++i) {
      if (water < plants[i]) {
        steps += i + i;
        water = capacity - plants[i];
      } else {
        water -= plants[i];
      }
    }
    return steps + plants.size();
  }
};
