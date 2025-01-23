#include <vector>

extern "C" {
double findMedianSortedArrays(
    int* nums1, int nums1Size, int* nums2, int nums2Size);
}

double solution_c(std::vector<int> nums1, std::vector<int> nums2) {
  return findMedianSortedArrays(
      nums1.data(), nums1.size(), nums2.data(), nums2.size());
}
