#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int* intersections = malloc(sizeof(int) * (nums1Size > nums2Size ? nums1Size : nums2Size));
  int* intersectionsIt = intersections - 1;

  qsort(nums1, nums1Size, sizeof(int), comp);
  qsort(nums2, nums2Size, sizeof(int), comp);

  int* nums1end = nums1 + nums1Size;
  int* nums2end = nums2 + nums2Size;
  while (nums1 < nums1end && nums2 < nums2end) {
    if (*nums1 == *nums2 && (intersectionsIt < intersections || *intersectionsIt != *nums1)) {
      ++intersectionsIt;
      *intersectionsIt = *nums1;
      ++nums1;
      ++nums2;
    } else {
      *nums1 < *nums2 ? ++nums1 : ++nums2;
    }
  }

  *returnSize = intersectionsIt + 1 - intersections;
  return intersections;
}
