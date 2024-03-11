#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int* intersections = malloc(sizeof(int) * (nums1Size > nums2Size ? nums1Size : nums2Size));
  *returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;

  (void)nums1;
  (void)nums2;

  return intersections;
}
