#include <stdlib.h>

int* resultArray(int* nums, int numsSize, int* returnSize) {
  int nums1Size = 1;

  int nums2Size = 0;
  int* nums2 = malloc(numsSize * sizeof(int));
  nums2[nums2Size++] = nums[1];

  for (int i = 2; i < numsSize; ++i) {
    if (nums[nums1Size - 1] > nums2[nums2Size - 1]) {
      nums[nums1Size++] = nums[i];
    } else {
      nums2[nums2Size++] = nums[i];
    }
  }

  for (int i = 0; i < nums2Size; ++i) {
    nums[nums1Size++] = nums2[i];
  }

  free(nums2);

  *returnSize = numsSize;
  return nums;
}
