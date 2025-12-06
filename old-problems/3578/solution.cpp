#include <queue>
#include <vector>

class Solution {
 public:
  int countPartitions(std::vector<int>& nums, int k) {
    long long sum{0}, next{1};
    std::priority_queue<std::tuple<int, std::size_t>> negMins{}, maxs{};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      negMins.push({-nums[r], r});
      maxs.push({nums[r], r});

      nums[r] = next;
      sum = (sum + next) % 1000000007;

      while (std::get<0>(maxs.top()) + std::get<0>(negMins.top()) > k) {
        if (std::get<1>(maxs.top()) < std::get<1>(negMins.top())) {
          const std::size_t ll{std::get<1>(maxs.top()) + 1};
          for (std::size_t i{l}; i < ll; ++i) {
            sum = (1000000007 + sum - nums[i]) % 1000000007;
          }
          l = ll;
          while (std::get<1>(maxs.top()) < l) maxs.pop();
        } else {
          const std::size_t ll{std::get<1>(negMins.top()) + 1};
          for (std::size_t i{l}; i < ll; ++i) {
            sum = (1000000007 + sum - nums[i]) % 1000000007;
          }
          l = ll;
          while (std::get<1>(negMins.top()) < l) negMins.pop();
        }
      }

      next = sum;
    }

    return sum;
  }
};
