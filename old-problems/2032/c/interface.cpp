#include <cstring>
#include <vector>

extern "C" {
int* twoOutOfThree(
    int* nums1, int nums1Size, int* nums2, int nums2Size,
    int* nums3, int nums3Size, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> nums1, std::vector<int> nums2, std::vector<int> nums3) {
  int returnSize{};
  int* returnData{
      twoOutOfThree(
          nums1.data(), nums1.size(), nums2.data(), nums2.size(),
          nums3.data(), nums3.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
