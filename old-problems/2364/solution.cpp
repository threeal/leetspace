#include <unordered_map>
#include <vector>

class Solution {
 public:
  long long countBadPairs(std::vector<int>& nums) {
    std::unordered_map<int, long long> freqs{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      ++freqs[nums[i] - i];
    }

    long long total = nums.size();
    total = total * (total - 1) / 2;

    for (const auto& [i, freq] : freqs) {
      total -= freq * (freq - 1) / 2;
    }

    return total;
  }
};
