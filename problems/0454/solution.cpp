#include <unordered_map>
#include <vector>

class Solution {
 public:
  int fourSumCount(
      std::vector<int>& nums1, std::vector<int>& nums2,
      std::vector<int>& nums3, std::vector<int>& nums4) {
    std::unordered_map<int, int> firstPairsCount{};
    for (const auto i : nums1) {
      for (const auto j : nums2) {
        ++firstPairsCount[i + j];
      }
    }

    int count{0};
    for (const auto k : nums3) {
      for (const auto l : nums4) {
        const auto it = firstPairsCount.find(-k - l);
        if (it != firstPairsCount.end()) count += it->second;
      }
    }

    return count;
  }
};
