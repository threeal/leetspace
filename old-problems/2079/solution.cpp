#include <vector>

class Solution {
 public:
  int wateringPlants(std::vector<int>& plants, int capacity) {
    return plants.size() + capacity;
  }
};
