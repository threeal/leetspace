#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int closestMeetingNode(
      std::vector<int>& edges, int node1, int node2) {
    int dist{0};
    std::vector<int> dist1(edges.size(), -1);
    while (node1 != -1 && dist1[node1] == -1) {
      dist1[node1] = dist++;
      node1 = edges[node1];
    }

    dist = 0;
    std::vector<int> dist2(edges.size(), -1);
    while (node2 != -1 && dist2[node2] == -1) {
      dist2[node2] = dist++;
      node2 = edges[node2];
    }

    int maxDist{std::numeric_limits<int>::max()};
    int res{-1};
    for (std::size_t i{0}; i < dist1.size(); ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        const int dist{std::max(dist1[i], dist2[i])};
        if (dist < maxDist) {
          maxDist = dist;
          res = i;
        }
      }
    }

    return res;
  }
};
