#include <vector>

class Solution {
 public:
  std::vector<int> shortestToChar(std::string s, char c) {
    std::vector<int> distances(s.size(), 0);

    int ci = s.size();
    for (std::size_t i{0}; i < s.size(); ++i, ++ci) {
      if (s[i] == c) ci = 0;
      distances[i] = ci;
    }

    for (std::size_t i{s.size()}; i > 0; --i, ++ci) {
      if (s[i - 1] == c) ci = 0;
      if (ci < distances[i - 1]) distances[i - 1] = ci;
    }

    return distances;
  }
};
