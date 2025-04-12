#include <queue>
#include <vector>

class Solution {
 private:
  using Pair = std::tuple<int, std::size_t, std::size_t>;

 public:
  std::vector<std::vector<int>> kSmallestPairs(
      std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pairs{};

    for (std::size_t i{0}; i < nums1.size(); ++i) {
      pairs.push({nums1[i] + nums2[0], i, 0});
    }

    std::vector<std::vector<int>> output(k, std::vector<int>(2));
    for (int i{0}; i < k; ++i) {
      const auto [val, i1, i2] = pairs.top();
      pairs.pop();

      output[i][0] = nums1[i1];
      output[i][1] = nums2[i2];

      if (i2 + 1 < nums2.size()) {
        pairs.push({nums1[i1] + nums2[i2 + 1], i1, i2 + 1});
      }
    }

    return output;
  }
};
