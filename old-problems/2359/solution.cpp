#include <vector>

class Solution {
 public:
  int closestMeetingNode(
      std::vector<int>& edges, int node1, int node2) {
    return edges.front() + node1 + node2;
  }
};
