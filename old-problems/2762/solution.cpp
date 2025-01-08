#include <deque>
#include <vector>

class Solution {
 public:
  long long continuousSubarrays(std::vector<int>& nums) {
    long long count{0};
    std::deque<int> mins{}, maxs{};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      while (!mins.empty() && nums[r] < mins.back()) mins.pop_back();
      mins.push_back(nums[r]);

      while (!maxs.empty() && nums[r] > maxs.back()) maxs.pop_back();
      maxs.push_back(nums[r]);

      while (maxs.front() - mins.front() > 2) {
        if (!mins.empty() && nums[l] == mins.front()) mins.pop_front();
        if (!maxs.empty() && nums[l] == maxs.front()) maxs.pop_front();
        ++l;
      }

      count += r + 1 - l;
    }
    return count;
  }
};
