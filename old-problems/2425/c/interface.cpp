#include <vector>

extern "C" {
int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size);
}

int solution_c(std::vector<int> nums1, std::vector<int> nums2) {
  return xorAllNums(nums1.data(), nums1.size(), nums2.data(), nums2.size());
}
