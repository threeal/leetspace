#include <unordered_map>
#include <vector>

class Solution {
 public:
  int tupleSameProduct(std::vector<int>& nums) {
    std::unordered_map<int, int> frequencies{};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        ++frequencies[nums[i] * nums[j]];
      }
    }

    int count{0};
    for (const auto& [product, freq] : frequencies) {
      count += freq * (freq - 1) * 4;
    }

    return count;
  }
};
