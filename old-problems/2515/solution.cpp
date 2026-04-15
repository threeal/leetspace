#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int closestTarget(
      std::vector<std::string>& words, std::string target, int startIndex) {
    const int n = words.size();
    int minDistance = n;
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        const int distance{
            std::min((n + startIndex - i) % n, (n - startIndex + i) % n)};
        if (distance < minDistance) minDistance = distance;
      }
    }
    return minDistance == n ? -1 : minDistance;
  }
};
