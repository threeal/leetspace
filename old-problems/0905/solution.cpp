#include <list>
#include <vector>

class Solution {
 public:
  std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    std::list<int> odd, even;

    for (const auto num : nums) {
      if (num % 2)
        odd.push_back(num);
      else
        even.push_back(num);
    }

    std::size_t i = 0;
    for (const auto num : even) {
      nums[i++] = num;
    }
    for (const auto num : odd) {
      nums[i++] = num;
    }

    return nums;
  }
};
