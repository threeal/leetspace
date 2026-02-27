#include <unordered_map>
#include <vector>

class Solution {
 public:
  int firstUniqueFreq(std::vector<int>& nums) {
    std::unordered_map<int, int> freqs{};
    for (int num : nums) ++freqs[num];

    std::vector<int> freqFreqs(nums.size() + 1, 0);
    for (const auto [num, freq] : freqs) ++freqFreqs[freq];

    for (int num : nums) {
      if (freqFreqs[freqs[num]] == 1) return num;
    }

    return -1;
  }
};
