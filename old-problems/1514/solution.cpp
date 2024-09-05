#include <vector>

class Solution {
 public:
  double maxProbability(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<double>& succProb, int start, int end) {
    std::vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;

    bool updated{true};
    while (updated) {
      updated = false;
      for (int i = edges.size() - 1; i >= 0; --i) {
        if (maxProb[edges[i][0]] * succProb[i] > maxProb[edges[i][1]]) {
          maxProb[edges[i][1]] = maxProb[edges[i][0]] * succProb[i];
          updated = true;
        }

        if (maxProb[edges[i][1]] * succProb[i] > maxProb[edges[i][0]]) {
          maxProb[edges[i][0]] = maxProb[edges[i][1]] * succProb[i];
          updated = true;
        }
      }
    }

    return maxProb[end];
  }
};
