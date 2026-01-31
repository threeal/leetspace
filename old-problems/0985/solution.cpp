#include <vector>

class Solution {
 public:
  std::vector<int> sumEvenAfterQueries(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    int sum{0};
    for (int num : nums) {
      if (num % 2 == 0) sum += num;
    }

    std::vector<int> output(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      if (nums[queries[i][1]] % 2 == 0) sum -= nums[queries[i][1]];
      nums[queries[i][1]] += queries[i][0];
      if (nums[queries[i][1]] % 2 == 0) sum += nums[queries[i][1]];
      output[i] = sum;
    }

    return output;
  }
};
