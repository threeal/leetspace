#include <vector>

class Solution {
 public:
  int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    int count{0};
    for (const int num2 : nums2) {
      const int div{num2 * k};
      for (const int num1 : nums1) {
        if (num1 % div == 0) ++count;
      }
    }
    return count;
  }
};
