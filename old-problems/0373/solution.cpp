#include <queue>
#include <vector>

class Solution {
 private:
  using Pair = std::tuple<int, std::size_t, std::size_t>;

 public:
  std::vector<std::vector<int>> kSmallestPairs(
      std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pairs{};
    std::vector<std::vector<bool>> exists(
        nums1.size(), std::vector(nums2.size(), false));

    pairs.push({ nums1[0] + nums2[0], 0, 0 });
    exists[0][0] = true;

    std::vector<std::vector<int>> output(k, std::vector<int>(2));
    for (int i{0}; i < k; ++i) {
      const auto [val, i1, i2] = pairs.top();
      pairs.pop();

      output[i][0] = nums1[i1];
      output[i][1] = nums2[i2];

      if (i1 + 1 < nums1.size() && !exists[i1 + 1][i2]) {
        pairs.push({ nums1[i1 + 1] + nums2[i2], i1 + 1, i2 });
        exists[i1 + 1][i2] = true;
      }

      if (i2 + 1 < nums2.size() && !exists[i1][i2 + 1]) {
        pairs.push({ nums1[i1] + nums2[i2 + 1], i1, i2 + 1 });
        exists[i1][i2 + 1] = true;
      }
    }

    return output;
  }
};
