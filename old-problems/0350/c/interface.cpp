#include <cstring>
#include <vector>

extern "C" {
int* intersect(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums1, std::vector<int> nums2) {
  int returnSize;
  const auto returnData = intersect(
      nums1.data(), nums1.size(), nums2.data(), nums2.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
