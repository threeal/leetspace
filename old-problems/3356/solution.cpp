#include <algorithm>
#include <vector>

class Solution {
 public:
  int minZeroArray(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::vector<int> sums(nums.size() + 1);

    int low{0}, high = queries.size();
    while (low < high) {
      const int mid{low + (high - low) / 2};
      if (verify(nums, queries, sums, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return verify(nums, queries, sums, low) ? low : -1;
  }

  static bool verify(
      const std::vector<int>& nums,
      const std::vector<std::vector<int>>& queries,
      std::vector<int>& sums, int k) {
    std::fill(sums.begin(), sums.end(), 0);
    for (int i{0}; i < k; ++i) {
      sums[queries[i][0]] += queries[i][2];
      sums[queries[i][1] + 1] -= queries[i][2];
    }

    int sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      sum += sums[i];
      if (nums[i] > sum) return false;
    }

    return true;
  }
};
