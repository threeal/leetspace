#include <vector>

class Solution {
 public:
  long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    long long zeros1{0}, sum1{0};
    for (const int num : nums1) {
      if (num == 0) {
        ++zeros1;
      } else {
        sum1 += num;
      }
    }

    long long zeros2{0}, sum2{0};
    for (const int num : nums2) {
      if (num == 0) {
        ++zeros2;
      } else {
        sum2 += num;
      }
    }

    if (zeros1 == 0) {
      if (zeros2 == 0) {
        return sum1 == sum2 ? sum1 : -1;
      } else {
        return sum1 >= sum2 + zeros2 ? sum1 : -1;
      }
    } else {
      if (zeros2 == 0) {
        return sum2 >= sum1 + zeros1 ? sum2 : -1;
      } else {
        return sum1 + zeros1 >= sum2 + zeros2
            ? sum1 + zeros1
            : sum2 + zeros2;
      }
    }
  }
};
