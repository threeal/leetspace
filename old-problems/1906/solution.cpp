#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> minDifference(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::vector<std::vector<int>> freqs{};
    freqs.reserve(nums.size() + 1);

    std::vector<int> freq(100, 0);
    freqs.push_back(freq);

    for (const auto num : nums) {
      ++freq[num - 1];
      freqs.push_back(freq);
    }

    std::vector<int> diffs{};
    diffs.reserve(queries.size());
    for (const auto& query : queries) {
      int diff{std::numeric_limits<int>::max()};

      int prev{0}, i{0};
      while (i < 100) {
        if (freqs[query[1] + 1][i] - freqs[query[0]][i] > 0) {
          prev = i;
          break;
        }
        ++i;
      }

      for (int i{prev + 1}; i < 100; ++i) {
        if (freqs[query[1] + 1][i] - freqs[query[0]][i] > 0) {
          if (i - prev < diff) diff = i - prev;
          prev = i;
        }
      }

      if (diff == std::numeric_limits<int>::max()) diff = -1;
      diffs.push_back(diff);
    }

    return diffs;
  }
};
