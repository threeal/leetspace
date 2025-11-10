#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> findXSum(std::vector<int>& nums, int k, int x) {
    --k;

    std::vector<int> freqs(51, 0);
    for (int i{0}; i < k; ++i) ++freqs[nums[i]];

    std::vector<int> indices(51);
    std::iota(indices.begin(), indices.end(), 0);

    std::vector<int> output(nums.size() - k);
    for (std::size_t i{0}; i < output.size(); ++i) {
      ++freqs[nums[i + k]];

      std::partial_sort(
          indices.begin(), indices.begin() + x, indices.end(),
          [&](const int a, const int b) {
            return freqs[a] == freqs[b] ? a > b : freqs[a] > freqs[b];
          });

      int sum{0};
      for (int i{0}; i < x; ++i) sum += indices[i] * freqs[indices[i]];
      output[i] = sum;

      --freqs[nums[i]];
    }

    return output;
  }
};
