#include <vector>

extern "C" {
bool uniformArray(int* nums1, int nums1Size);
}

bool solution_c(std::vector<int> nums1) {
  return uniformArray(nums1.data(), nums1.size());
}
