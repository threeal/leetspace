#include <algorithm>
#include <vector>

class Solution {
 public:
  bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
    std::sort(asteroids.begin(), asteroids.end());
    long long llmass = mass;
    for (const int asteroid : asteroids) {
      if (asteroid > llmass) return false;
      llmass += asteroid;
    }
    return true;
  }
};
