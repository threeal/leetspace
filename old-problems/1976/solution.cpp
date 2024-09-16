#include <list>
#include <numeric>
#include <queue>
#include <vector>

struct Node {
  int idx;
  long long time;
};

bool operator>(const Node& a, const Node& b) {
  return a.time > b.time;
}

class Solution {
 public:
  int countPaths(int n, std::vector<std::vector<int>>& roads) {
    std::vector<std::list<Node>> nextsOf(n);
    for (const auto& road : roads) {
      nextsOf[road[0]].push_back({.idx = road[1], .time = road[2]});
      nextsOf[road[1]].push_back({.idx = road[0], .time = road[2]});
    }

    std::vector<long long> times(n, std::numeric_limits<long long>::max());
    std::vector<int> counts(n, 0);
    counts.front() = 1;

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue{};
    queue.push({.idx = 0, .time = 0});
    while (!queue.empty()) {
      const auto curr = queue.top();
      queue.pop();
      if (curr.time > times[curr.idx]) continue;
      for (const auto next : nextsOf[curr.idx]) {
        const auto time = curr.time + next.time;
        if (time > times[next.idx]) continue;
        if (time < times[next.idx]) {
          times[next.idx] = time;
          counts[next.idx] = counts[curr.idx];
          queue.push({.idx = next.idx, .time = time});
        } else {
          counts[next.idx] = (counts[curr.idx] + counts[next.idx]) % 1000000007;
        }
      }
    }

    return counts.back();
  }
};
