#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int findRotateSteps(std::string ring, std::string key) {
    for (auto &c : ring) c -= 'a';
    for (auto &c : key) c -= 'a';

    std::vector<std::vector<int>> distances(ring.size(), std::vector(26, 101));
    std::vector<std::vector<int>> nexts{std::vector(ring.size(), std::vector<int>(26))};

    for (int i{0}; i < static_cast<int>(ring.size()); ++i) {
      for (int j{0}; j < i; ++j) {
        const int distance{std::min(i - j, static_cast<int>(ring.size()) + j - i)};
        if (distance < distances[i][ring[j]]) {
          nexts[i][ring[j]] = j;
          distances[i][ring[j]] = distance;
        }
      }

      nexts[i][ring[i]] = i;
      distances[i][ring[i]] = 0;

      for (int j{i + 1}; j < static_cast<int>(ring.size()); ++j) {
        const int distance{std::min(j - i, static_cast<int>(ring.size()) + i - j)};
        if (distance < distances[i][ring[j]]) {
          nexts[i][ring[j]] = j;
          distances[i][ring[j]] = distance;
        }
      }
    }

    int steps{0};
    int index{0};
    for (const auto c : key) {
      steps += distances[index][c] + 1;
      index = nexts[index][c];
    }

    return steps;
  }
};
