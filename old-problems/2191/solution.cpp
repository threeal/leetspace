#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> sortJumbled(
      std::vector<int>& mapping, std::vector<int>& nums) {
    std::vector<int> mappedNums(nums.size());
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        mappedNums[i] = mapping[0];
      } else {
        int num{nums[i]}, mappedNum{0}, exp{1};
        while (num != 0) {
          mappedNum += mapping[num % 10] * exp;
          num /= 10;
          exp *= 10;
        }
        mappedNums[i] = mappedNum;
      }
    }

    std::vector<int> indices(nums.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(), [&mappedNums](int i, int j) {
      return mappedNums[i] != mappedNums[j]
          ? mappedNums[i] < mappedNums[j]
          : i < j;
    });

    for (auto& index : indices) {
      index = nums[index];
    }

    return indices;
  }
};
