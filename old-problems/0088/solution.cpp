#include <cstring>
#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (--n < 0) return;

    if (--m < 0) {
      std::memcpy(nums1.data(), nums2.data(), ++n * sizeof(int));
      return;
    }

    for (int i = nums1.size() - 1; i >= 0; --i) {
      if (nums1[m] > nums2[n]) {
        nums1[i] = nums1[m];
        if (--m < 0) {
          std::memcpy(nums1.data(), nums2.data(), ++n * sizeof(int));
          return;
        }
      } else {
        nums1[i] = nums2[n];
        if (--n < 0) return;
      }
    }
  }
};
