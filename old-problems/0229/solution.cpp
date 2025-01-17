#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> majorityElement(std::vector<int>& nums) {
    int majority1{0}, majority2{0}, count1{0}, count2{0};
    for (const auto num : nums) {
      if (num == majority1) {
        ++count1;
      } else if (num == majority2) {
        ++count2;
      } else if (count1 == 0) {
        majority1 = num;
        ++count1;
      } else if (count2 == 0) {
        majority2 = num;
        ++count2;
      } else {
        --count1;
        --count2;
      }
    }

    count1 = 0;
    count2 = 0;
    for (const auto num : nums) {
      if (num == majority1) {
        ++count1;
      } else if (num == majority2) {
        ++count2;
      }
    }

    const int limit = nums.size() / 3;
    if (count1 > limit) {
      return count2 > limit
          ? std::vector<int>{majority1, majority2}
          : std::vector<int>{majority1};
    } else {
      return count2 > limit
          ? std::vector<int>{majority2}
          : std::vector<int>{};
    }
  }
};
