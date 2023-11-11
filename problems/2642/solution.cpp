class Graph {
 private:
  unordered_map<int, unordered_map<int, int>> distances;

 public:
  Graph(int n, vector<vector<int>>& edges) {
    (void)n;
    for (const auto& edge : edges) {
      distances[edge[0]][edge[1]] = edge[2];
    }
  }

  void addEdge(vector<int> edge) {
    distances[edge[0]][edge[1]] = edge[2];
  }

  int shortestPath(int node1, int node2) {
    unordered_set<int> visited;
    unordered_map<int, int> steps = {{node1, 0}};
    while (!steps.empty()) {
      const auto step = min_element(
          steps.begin(), steps.end(), [](const auto& a, const auto& b) -> bool {
            return a.second < b.second;
          });

      if (step->first == node2) return step->second;

      for (const auto& [node, distance] : distances[step->first]) {
        if (visited.contains(node)) continue;
        steps[node] = steps[node] > 0
            ? min(steps[node], step->second + distance)
            : step->second + distance;
      }

      visited.insert(step->first);
      steps.erase(step);
    }
    return -1;
  }
};
