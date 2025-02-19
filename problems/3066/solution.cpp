#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int k) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>>
        queue(nums.begin(), nums.end());

    int count{0};
    while (queue.top() < k) {
      const long long a{queue.top()};
      queue.pop();

      const long long b{queue.top()};
      queue.pop();

      queue.push(std::min(a, b) * 2 + std::max(b, a));
      ++count;
    }

    return count;
  }
};
