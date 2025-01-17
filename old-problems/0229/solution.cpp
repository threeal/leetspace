#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (auto num : nums) {
      ++counts[num];
    }

    std::vector<int> result;
    const int threshold = nums.size() / 3;
    for (auto [num, count] : counts) {
      if (count > threshold) result.push_back(num);
    }

    std::sort(result.begin(), result.end());
    return result;
  }
};
