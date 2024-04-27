#include <algorithm>
#include <limits>
#include <list>
#include <string>
#include <vector>

class Solution {
 public:
  int findRotateSteps(std::string ring, std::string key) {
    for (auto& c : ring) c -= 'a';
    for (auto& c : key) c -= 'a';

    std::vector<std::list<std::size_t>> positions(26);
    for (std::size_t i{0}; i < ring.size(); ++i) {
      positions[ring[i]].push_back(i);
    }

    std::vector<std::vector<int>> cache(ring.size(), std::vector(key.size(), -1));
    return findRotateSteps(ring, key, positions, cache, 0, 0);
  }

  int findRotateSteps(
      const std::string& ring,
      const std::string& key,
      const std::vector<std::list<std::size_t>>& positions,
      std::vector<std::vector<int>>& cache,
      std::size_t ringPos,
      std::size_t keyPos) {
    if (keyPos == key.size()) return 0;

    if (cache[ringPos][keyPos] < 0) {
      int minStep{std::numeric_limits<int>::max()};
      for (const auto pos : positions[key[keyPos]]) {
        const int distance = pos > ringPos
            ? std::min(pos - ringPos, ring.size() + ringPos - pos)
            : std::min(ringPos - pos, ring.size() + pos - ringPos);
        int step{1 + distance + findRotateSteps(ring, key, positions, cache, pos, keyPos + 1)};
        if (step < minStep) minStep = step;
      }
      cache[ringPos][keyPos] = minStep;
    }

    return cache[ringPos][keyPos];
  }
};
