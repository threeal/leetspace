#include <vector>

class Solution {
 public:
  std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
    std::vector<int> temps{};
    std::size_t numsSize{0};
    int pivotCount{0};

    for (const auto num : nums) {
      if (num == pivot) {
        ++pivotCount;
      } else if (num < pivot) {
        nums[numsSize++] = num;
      } else {
        temps.push_back(num);
      }
    }

    while (--pivotCount >= 0) nums[numsSize++] = pivot;
    for (const auto temp : temps) nums[numsSize++] = temp;

    return nums;
  }
};
