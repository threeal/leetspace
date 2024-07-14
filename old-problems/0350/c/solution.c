#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* intersect(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  qsort(nums1, nums1Size, sizeof(int), compare);
  qsort(nums2, nums2Size, sizeof(int), compare);

  int* nums = nums1Size > nums2Size ? nums1 : nums2;

  int i = 0, i1 = 0, i2 = 0;
  while (1) {
    if (nums1[i1] == nums2[i2]) {
      nums[i] = nums1[i1];
      ++i;
      if (++i1 == nums1Size) break;
      if (++i2 == nums2Size) break;
    } else if (nums1[i1] < nums2[i2]) {
      if (++i1 == nums1Size) break;
    } else {
      if (++i2 == nums2Size) break;
    }
  }

  *returnSize = i;
  return nums;
}
