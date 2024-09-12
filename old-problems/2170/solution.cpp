#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums) {
    std::unordered_map<int, int> oddFreqs{}, evenFreqs{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      ++oddFreqs[nums[i]];
      if (++i >= nums.size()) break;
      ++evenFreqs[nums[i]];
    }

    int oddFreq1{0}, oddFreq2{0}, oddNum{-1};
    for (const auto& [num, freq] : oddFreqs) {
      if (freq > oddFreq2) {
        if (freq > oddFreq1) {
          oddFreq2 = oddFreq1;
          oddFreq1 = freq;
          oddNum = num;
        } else {
          oddFreq2 = freq;
        }
      }
    }

    int evenFreq1{0}, evenFreq2{0}, evenNum{-1};
    for (const auto& [num, freq] : evenFreqs) {
      if (freq > evenFreq2) {
        if (freq > evenFreq1) {
          evenFreq2 = evenFreq1;
          evenFreq1 = freq;
          evenNum = num;
        } else {
          evenFreq2 = freq;
        }
      }
    }

    return oddNum == evenNum
        ? nums.size() - std::max(oddFreq1 + evenFreq2, oddFreq2 + evenFreq1)
        : nums.size() - oddFreq1 - evenFreq1;
  }
};
