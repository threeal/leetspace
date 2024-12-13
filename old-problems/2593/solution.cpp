#include <queue>
#include <vector>

class Solution {
 public:
  long long findScore(std::vector<int>& nums) {
    const auto compare = [&](std::size_t a, std::size_t b) {
      return nums[a] == nums[b] ? a > b : nums[a] > nums[b];
    };

    std::priority_queue<
        std::size_t, std::vector<std::size_t>, decltype(compare)>
        pq(compare);

    for (std::size_t i{0}; i < nums.size(); ++i) pq.push(i);

    std::vector<bool> marked(nums.size(), false);

    long long score{0};
    while (!pq.empty()) {
      if (!marked[pq.top()]) {
        score += nums[pq.top()];
        marked[pq.top()] = true;
        if (pq.top() > 0) marked[pq.top() - 1] = true;
        if (pq.top() + 1 < marked.size()) marked[pq.top() + 1] = true;
      }
      pq.pop();
    }

    return score;
  }
};
