#include <vector>

class Solution {
 public:
  bool uniformArray(std::vector<int>& nums1) {
    int oddCount{nums1[0] % 2}, minNum{nums1[0]};
    for (std::size_t i{1}; i < nums1.size(); ++i) {
      oddCount += nums1[i] % 2;
      if (nums1[i] < minNum) minNum = nums1[i];
    }
    return oddCount == 0 || minNum % 2 == 1;
  }
};
