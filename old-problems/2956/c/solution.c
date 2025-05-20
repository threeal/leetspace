#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* findIntersectionValues(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  qsort(nums1, nums1Size, sizeof(int), compare);
  qsort(nums2, nums2Size, sizeof(int), compare);

  int i1 = 0, i2 = 0, count1 = 0, count2 = 0;
  while (i1 < nums1Size && i2 < nums2Size) {
    if (nums1[i1] >= nums2[i2]) {
      while (i2 < nums2Size && nums2[i2] < nums1[i1]) ++i2;
      if (i2 == nums2Size) break;
    } else {
      while (i1 < nums1Size && nums1[i1] < nums2[i2]) ++i1;
      if (i1 == nums1Size) break;
    }

    if (nums1[i1] == nums2[i2]) {
      const int num = nums1[i1];
      while (i1 < nums1Size && nums1[i1] == num) ++i1, ++count1;
      while (i2 < nums2Size && nums2[i2] == num) ++i2, ++count2;
    }
  }

  static int output[2];
  output[0] = count1;
  output[1] = count2;

  *returnSize = 2;
  return output;
}
