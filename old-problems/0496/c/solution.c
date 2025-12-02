#include <stdlib.h>

int* nextGreaterElement(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int indices[10001] = {0};
  for (int i = 0; i < nums1Size; ++i) {
    indices[nums1[i]] = i + 1;
  }

  int* greaters = malloc(nums2Size * sizeof(int));
  int greatersSize = 0;

  for (int i = nums2Size - 1; i >= 0; --i) {
    if (indices[nums2[i]] != 0) {
      while (greatersSize != 0 && greaters[greatersSize - 1] <= nums2[i]) {
        --greatersSize;
      }
      nums1[indices[nums2[i]] - 1] =
          greatersSize == 0 ? -1 : greaters[greatersSize - 1];
    }
    greaters[greatersSize++] = nums2[i];
  }

  free(greaters);

  *returnSize = nums1Size;
  return nums1;
}
