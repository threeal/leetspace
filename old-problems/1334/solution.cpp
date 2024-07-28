#include <limits>
#include <vector>

class Solution {
 public:
  int findTheCity(
      int n, std::vector<std::vector<int>>& edges,
      int distanceThreshold) {
    std::vector<std::vector<int>> distances(
        n, std::vector<int>(n, std::numeric_limits<int>::max()));

    for (int i{n - 1}; i >= 0; --i) {
      distances[i][i] = 0;
    }

    for (const auto& edge : edges) {
      distances[edge[0]][edge[1]] = edge[2];
      distances[edge[1]][edge[0]] = edge[2];
    }

    for (int i{n - 1}; i >= 0; --i) {
      for (int j{n - 1}; j >= 0; --j) {
        if (distances[i][j] == std::numeric_limits<int>::max()) continue;
        for (int k{n - 1}; k >= 0; --k) {
          if (distances[j][k] == std::numeric_limits<int>::max()) continue;
          if (distances[i][j] + distances[j][k] < distances[i][k]) {
            distances[i][k] = distances[i][j] + distances[j][k];
            distances[k][i] = distances[i][j] + distances[j][k];
          }
        }
      }
    }

    int theCity{n};
    int theCount{std::numeric_limits<int>::max()};
    for (int i{n - 1}; i >= 0; --i) {
      int count{0};
      for (int j{n - 1}; j >= 0; --j) {
        if (distances[i][j] <= distanceThreshold) ++count;
      }

      if (count < theCount) {
        theCity = i;
        theCount = count;
      }
    }

    return theCity;
  }
};
