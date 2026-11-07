#include <algorithm>
#include <queue>
#include <string>
#include <vector>

class Solution {
 private:
  struct State {
    int weight;
    int node;
    int count;
  };

  struct CompareState {
    bool operator()(const State& a, const State& b) const {
      return a.weight > b.weight;
    }
  };

 public:
  int shortestPath(
      int n, std::vector<std::vector<int>>& edges, std::string labels, int k) {
    std::sort(
        edges.begin(), edges.end(), [](const auto& a, const auto& b) {
          return a[0] < b[0];
        });

    std::vector<std::size_t> edgesBegin(n, edges.size());
    for (std::size_t i{0}; i < edges.size(); ++i) {
      if (edgesBegin[edges[i][0]] == edges.size()) edgesBegin[edges[i][0]] = i;
    }

    std::priority_queue<State, std::vector<State>, CompareState> pq{};
    pq.push({.weight = 0, .node = 0, .count = 1});

    while (!pq.empty()) {
      const auto state = pq.top();
      if (state.node == n - 1) return state.weight;
      pq.pop();

      for (std::size_t i{edgesBegin[state.node]}; i < edges.size(); ++i) {
        if (edges[i][0] != state.node) break;

        State nextState{state};
        nextState.weight += edges[i][2];
        nextState.node = edges[i][1];
        if (labels[state.node] == labels[nextState.node]) {
          ++nextState.count;
        } else {
          nextState.count = 1;
        }

        if (nextState.count <= k) {
          pq.push(nextState);
        }
      }
    }

    return -1;
  }
};
