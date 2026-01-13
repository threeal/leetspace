#include <deque>
#include <vector>

class Solution {
 public:
  int countPartitions(std::vector<int>& nums, int k) {
    long long sum{0};
    std::vector<long long> sums(nums.size() + 1);
    sums[0] = 1;

    std::deque<std::size_t> mins{}, maxs{};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      while (!mins.empty() && nums[mins.back()] >= nums[r]) mins.pop_back();
      mins.push_back(r);

      while (!maxs.empty() && nums[maxs.back()] <= nums[r]) maxs.pop_back();
      maxs.push_back(r);

      sum = (sum + sums[r]) % 1000000007;

      while (nums[maxs.front()] - nums[mins.front()] > k) {
        if (mins.front() < maxs.front()) {
          const std::size_t ll{mins.front() + 1};
          mins.pop_front();

          for (std::size_t i{l}; i < ll; ++i) {
            sum = (1000000007 + sum - sums[i]) % 1000000007;
          }
          l = ll;
        } else {
          const std::size_t ll{maxs.front() + 1};
          maxs.pop_front();

          for (std::size_t i{l}; i < ll; ++i) {
            sum = (1000000007 + sum - sums[i]) % 1000000007;
          }
          l = ll;
        }
      }

      sums[r + 1] = sum;
    }

    return sum;
  }
};
