#include <vector>

extern "C" {
int closestMeetingNode(int* edges, int edgesSize, int node1, int node2);
}

int solution_c(std::vector<int> edges, int node1, int node2) {
  return closestMeetingNode(edges.data(), edges.size(), node1, node2);
}
