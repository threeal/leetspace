#include <cstring>
#include <vector>

extern "C" {
int** mergeArrays(
    int** nums1, int nums1Size, int* nums1ColSize,
    int** nums2, int nums2Size, int* nums2ColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> nums1, std::vector<std::vector<int>> nums2) {
  std::vector<int*> nums1Datas(nums1.size());
  std::vector<int> nums1Sizes(nums1.size());
  for (std::size_t i{0}; i < nums1.size(); ++i) {
    nums1Datas[i] = nums1[i].data();
    nums1Sizes[i] = nums1[i].size();
  }

  std::vector<int*> nums2Datas(nums2.size());
  std::vector<int> nums2Sizes(nums2.size());
  for (std::size_t i{0}; i < nums2.size(); ++i) {
    nums2Datas[i] = nums2[i].data();
    nums2Sizes[i] = nums2[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  int** returnData = mergeArrays(
      nums1Datas.data(), nums1.size(), nums1Sizes.data(),
      nums2Datas.data(), nums2.size(), nums2Sizes.data(),
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
