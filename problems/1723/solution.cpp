#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int minimumTimeRequired(std::vector<int>& jobs, int k) {
    std::sort(jobs.begin(), jobs.end());
    std::vector<int> workers(k, 0);
    return dfs(jobs.data(), jobs.size() - 1, workers.data(), k, 0);
  }

  int dfs(int* jobs, int i, int* workers, int k, int time) {
    if (i < 0) return time;
    int minTime{std::numeric_limits<int>::max()};

    std::unordered_set<int> seen{};
    for (int j{k - 1}; j >= 0; --j) {
      if (time >= minTime) break;
      if (!seen.insert(workers[j]).second) continue;
      if (workers[j] + jobs[i] >= minTime) continue;

      workers[j] += jobs[i];
      minTime = std::min(
          minTime, dfs(jobs, i - 1, workers, k, std::max(time, workers[j])));
      workers[j] -= jobs[i];
    }

    return minTime;
  }
};
