#include <algorithm>
#include <vector>

class Solution {
 public:
  int tupleSameProduct(std::vector<int>& nums) {
    std::vector<int> products{};
    products.reserve(nums.size() * (nums.size() - 1) / 2);

    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        products.push_back(nums[i] * nums[j]);
      }
    }

    std::sort(products.begin(), products.end());

    int count{0};
    for (std::size_t i{1}; i < products.size(); ++i) {
      int n{1};
      while (i < products.size() && products[i] == products[i - 1]) {
        ++i;
        ++n;
      }
      count += n * (n - 1) * 4;
    }

    return count;
  }
};
