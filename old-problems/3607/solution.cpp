#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> processQueries(
      int c, std::vector<std::vector<int>>& connections,
      std::vector<std::vector<int>>& queries) {
    std::vector<bool> isOnlines(c + 1, true);

    std::vector<int> roots(c + 1);
    std::iota(roots.begin(), roots.end(), 0);

    for (const auto& connection : connections) {
      const int root0{findRoot(roots, connection[0])};
      const int root1{findRoot(roots, connection[1])};
      if (root0 != root1) {
        if (root0 < root1) {
          roots[root1] = root0;
        } else {
          roots[root0] = root1;
        }
      }
    }

    std::vector<std::vector<int>> queues(c + 1);
    for (int x{1}; x <= c; ++x) {
      queues[findRoot(roots, x)].push_back(x);
    }

    for (auto& queue : queues) {
      std::sort(queue.begin(), queue.end(), std::greater<int>());
    }

    std::vector<int> output{};
    for (const auto& query : queries) {
      if (query[0] == 1) {
        if (isOnlines[query[1]]) {
          output.push_back(query[1]);
        } else {
          const int root{findRoot(roots, query[1])};
          while (!queues[root].empty() && !isOnlines[queues[root].back()]) {
            queues[root].pop_back();
          }
          output.push_back(queues[root].empty() ? -1 : queues[root].back());
        }
      } else {
        isOnlines[query[1]] = false;
      }
    }

    return output;
  }

 private:
  static int findRoot(std::vector<int>& roots, int x) {
    return roots[x] == x ? x : (roots[x] = findRoot(roots, roots[x]));
  }
};
