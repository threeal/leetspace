#include <vector>

class Solution {
 public:
  std::vector<bool> pathExistenceQueries(
      int n, std::vector<int>& nums, int maxDiff,
      std::vector<std::vector<int>>& queries) {
    (void)n;

    int prev{nums[0]}, group{0};
    nums[0] = group;

    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] - prev > maxDiff) ++group;
      prev = nums[i];
      nums[i] = group;
    }

    std::vector<bool> results(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      results[i] = nums[queries[i][0]] == nums[queries[i][1]];
    }

    return results;
  }
};
