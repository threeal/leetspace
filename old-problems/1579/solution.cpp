#include <vector>

class Unions {
 private:
  int components;
  std::vector<int> parentOf;

 public:
  Unions(int n) : components(n), parentOf(n + 1) {
    for (int i{n}; i >= 0; --i) {
      parentOf[i] = i;
    }
  }

  int findRootOf(int i) {
    if (parentOf[i] != i) parentOf[i] = findRootOf(parentOf[i]);
    return parentOf[i];
  }

  bool unite(int a, int b) {
    int rootA{findRootOf(a)};
    int rootB{findRootOf(b)};
    if (rootA == rootB) return false;
    if (rootA < rootB) {
      parentOf[rootA] = rootB;
    } else {
      parentOf[rootB] = rootA;
    }
    --components;
    return true;
  }

  bool isAllConnected() const {
    return components == 1;
  }
};

class Solution {
 public:
  int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
    int requiredEdges{0};
    Unions alice(n);
    for (const auto& edge : edges) {
      if (edge[0] == 3 && alice.unite(edge[1], edge[2])) ++requiredEdges;
    }

    auto bob = alice;
    for (const auto& edge : edges) {
      switch (edge[0]) {
        case 1:
          if (alice.unite(edge[1], edge[2])) ++requiredEdges;
          break;

        case 2:
          if (bob.unite(edge[1], edge[2])) ++requiredEdges;
          break;
      }
    }

    return alice.isAllConnected() && bob.isAllConnected()
        ? edges.size() - requiredEdges
        : -1;
  }
};
