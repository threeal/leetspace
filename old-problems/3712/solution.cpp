#include <unordered_map>
#include <vector>

class Solution {
 public:
  int sumDivisibleByK(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freqs{};
    for (const int num : nums) ++freqs[num];

    int sum{0};
    for (const auto [num, freq] : freqs) {
      if (freq % k == 0) sum += num * freq;
    }

    return sum;
  }
};
