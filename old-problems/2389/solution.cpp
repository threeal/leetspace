#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> answerQueries(
      std::vector<int>& nums, std::vector<int>& queries) {
    std::vector<std::size_t> queryIndices(queries.size());
    std::iota(queryIndices.begin(), queryIndices.end(), 0);

    std::sort(nums.begin(), nums.end());

    std::sort(
        queryIndices.begin(), queryIndices.end(),
        [&](const std::size_t a, const std::size_t b) {
          return queries[a] < queries[b];
        });

    int sum{0};
    std::size_t numsI{0};
    for (const std::size_t i : queryIndices) {
      while (numsI < nums.size() && sum + nums[numsI] <= queries[i]) {
        sum += nums[numsI++];
      }
      queries[i] = numsI;
    }

    return queries;
  }
};
