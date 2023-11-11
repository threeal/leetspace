class Graph {
 private:
  // Used to store the distance between two nodes.
  unordered_map<int, unordered_map<int, int>> distances;

 public:
  Graph(int /*n*/, vector<vector<int>>& edges) {
    // Store the given list of edges in a distances map.
    for (const auto& edge : edges) {
      distances[edge[0]][edge[1]] = edge[2];
    }
  }

  void addEdge(vector<int> edge) {
    // Add the given edge to the distances map.
    distances[edge[0]][edge[1]] = edge[2];
  }

  // Use a Dijkstra's-like algorithm to find the shortest path between two nodes.
  // Recursively, from the nearest unvisited node, step to the neighboring unvisited nodes
  // until it finds the target node or there are no more nodes left to visit.
  int shortestPath(int node1, int node2) {
    unordered_set<int> visited;
    unordered_map<int, int> steps = {{node1, 0}};

    // Repeat as long as there are unvisited nodes.
    while (!steps.empty()) {
      // Get the nearest unvisited node.
      const auto step = min_element(
          steps.begin(), steps.end(), [](const auto& a, const auto& b) -> bool {
            return a.second < b.second;
          });

      // Return the distance if the nearest unvisited node is the target node.
      if (step->first == node2) return step->second;

      // Step to the unvisited neighboring nodes from the nearest unvisited node.
      for (const auto& [node, distance] : distances[step->first]) {
        if (visited.contains(node)) continue;
        steps[node] = steps[node] > 0
            ? min(steps[node], step->second + distance)
            : step->second + distance;
      }

      // Mark the nearest unvisited node as visited.
      visited.insert(step->first);
      steps.erase(step);
    }

    // The given nodes are not connected.
    return -1;
  }
};
