#include <iostream>
#include <list>
#include <numeric>
#include <tuple>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> modifiedGraphEdges(
      int n, std::vector<std::vector<int>>& edges,
      int source, int destination, int target) {
    std::vector<std::list<std::tuple<int, int*>>> connections(n);
    for (auto& edge : edges) {
      connections[edge[0]].push_back({edge[1], edge.data() + 2});
      connections[edge[1]].push_back({edge[0], edge.data() + 2});
    }

    std::cout << "======" << std::endl;
    std::vector<bool> parents(n, false);
    const auto minDistance = explore(
        connections, parents, source, destination, target, nullptr);
    std::cout << minDistance << " " << target << std::endl;
    if (minDistance != target) return {};

    return edges;
  }

 private:
  static int explore(
      const std::vector<std::list<std::tuple<int, int*>>>& connections,
      std::vector<bool>& parents, int source, int destination, int target, int* lastWeight) {
    int minDistance{std::numeric_limits<int>::max()};
    for (const auto& [next, weight] : connections[source]) {
      if (parents[next] || *weight > target) continue;
      std::cout << source << " " << next << " " << minDistance << std::endl;
      if (next == destination) {
        if (*weight < 0) {
          *weight = target;
          if (target < minDistance) minDistance = target;
        } else if (*weight == target) {
          if (target < minDistance) minDistance = target;
        } else if (lastWeight != nullptr) {
          lastWeight += target - *weight;
          if (target < minDistance) minDistance = target;
        }
      } else {
        parents[source] = true;
        if (*weight < 0) {
          *weight = 1;
          const auto distance = explore(
              connections, parents, next, destination, target - 1, weight);
          if (distance == std::numeric_limits<int>::max()) continue;
          if (1 + distance < minDistance) minDistance = 1 + distance;
          *weight =
        } else {
          const auto distance = explore(
              connections, parents, next, destination,
              target - *weight, lastWeight);
          if (distance == std::numeric_limits<int>::max()) continue;
          if (*weight + distance < minDistance) {
            minDistance = *weight + distance;
          }
        }
        parents[source] = false;
      }
    }
    for (const auto parent : parents) {
      std::cout << (parent ? '1' : '0');
    }
    std::cout << " " << source << " " << minDistance << std::endl;
    return minDistance;
  }
};
