#include <vector>

extern "C" {
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size);
}

int solution_c(std::vector<int> nums1, std::vector<int> nums2) {
  return minNumber(nums1.data(), nums1.size(), nums2.data(), nums2.size());
}
