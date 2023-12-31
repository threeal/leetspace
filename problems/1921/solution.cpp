#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
    // Calculate the time required before enemies reach distance zero.
    int n = std::min(dist.size(), speed.size());
    for (int i = 0; i < n; ++i) {
      dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0 ? 1 : 0);
    }

    // Sort the time required from lowest to highest.
    std::sort(dist.begin(), dist.end());

    // Time equals to kills. Iterate through the time required as long as the current time is not greater than the time required.
    int kills = 0;
    for (const auto val : dist) {
      if (kills + 1 > val) break;
      ++kills;
    }

    return kills;
  }
};
