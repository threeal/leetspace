#include <vector>

extern "C" {
int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size);
}

int solution_c(std::vector<int> nums1, std::vector<int> nums2) {
  return maxDistance(nums1.data(), nums1.size(), nums2.data(), nums2.size());
}
