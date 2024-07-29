#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> queue(stones.begin(), stones.end());
    while (queue.size() > 1) {
      int stone{queue.top()};
      queue.pop();
      stone -= queue.top();
      queue.pop();
      if (stone > 0) queue.push(stone);
    }
    return queue.empty() ? 0 : queue.top();
  }
};
