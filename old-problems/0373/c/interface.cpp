#include <cstring>
#include <vector>

extern "C" {
int** kSmallestPairs(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int k,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> nums1, std::vector<int> nums2, int k) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData = kSmallestPairs(
      nums1.data(), nums1.size(), nums2.data(), nums2.size(), k,
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
