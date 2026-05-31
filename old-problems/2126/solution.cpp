#include <vector>

class Solution {
 public:
  bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
    return mass == 0 && asteroids.empty();
  }
};
