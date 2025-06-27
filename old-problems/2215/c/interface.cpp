#include <cstring>
#include <vector>

extern "C" {
int** findDifference(
    int* nums1, int nums1Size, int* nums2, int nums2Size,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> nums1, std::vector<int> nums2) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      findDifference(
          nums1.data(), nums1.size(), nums2.data(), nums2.size(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
