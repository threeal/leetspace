#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> survivedRobotsHealths(
      std::vector<int>& positions,
      std::vector<int>& healths,
      std::string directions) {
    std::vector<std::size_t> indexes(positions.size());
    for (std::size_t i{indexes.size() - 1}; i > 0; --i) {
      indexes[i] = i;
    }
    indexes[0] = 0;

    const auto positionsData = positions.data();
    std::sort(
        indexes.begin(), indexes.end(),
        [positionsData](const std::size_t a, const std::size_t b) {
          return positionsData[a] < positionsData[b];
        });

    std::stack<int> rights{};
    for (const auto index : indexes) {
      if (directions[index] == 'R') {
        rights.push(index);
      } else {
        while (!rights.empty() && healths[index] > 0) {
          if (healths[index] >= healths[rights.top()]) {
            if (healths[index] == healths[rights.top()]) {
              healths[index] = 0;
            } else {
              --healths[index];
            }
            healths[rights.top()] = 0;
            rights.pop();
          } else {
            --healths[rights.top()];
            healths[index] = 0;
          }
        }
      }
    }

    std::size_t healthsSize{0};
    for (const auto health : healths) {
      if (health == 0) continue;
      healths[healthsSize] = health;
      ++healthsSize;
    }

    healths.resize(healthsSize);
    return healths;
  }
};
