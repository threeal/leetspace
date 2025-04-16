#include <unordered_map>
#include <vector>

class Solution {
 public:
  long long countGood(std::vector<int>& nums, int k) {
    long long count{0};
    std::unordered_map<int, int> freqs{};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      k -= freqs[nums[r]]++;
      while (k <= 0) {
        count += nums.size() - r;
        k += --freqs[nums[l++]];
      }
    }
    return count;
  }
};
