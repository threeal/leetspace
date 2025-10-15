#include <stdbool.h>
#include <stdlib.h>

int* twoOutOfThree(
    int* nums1, int nums1Size, int* nums2, int nums2Size,
    int* nums3, int nums3Size, int* returnSize) {
  int* output = malloc((nums1Size + nums2Size + nums3Size) * sizeof(int));
  int outputSize = 0;

  bool exists[101] = {false};
  bool visited[101] = {false};

  for (int i = 0; i < nums1Size; ++i) {
    exists[nums1[i]] = true;
  }

  for (int i = 0; i < nums2Size; ++i) {
    if (!visited[nums2[i]]) {
      visited[nums2[i]] = true;
      if (exists[nums2[i]]) {
        exists[nums2[i]] = false;
        output[outputSize++] = nums2[i];
      } else {
        exists[nums2[i]] = true;
      }
    }
  }

  for (int i = 0; i < 101; ++i) visited[i] = false;

  for (int i = 0; i < nums3Size; ++i) {
    if (!visited[nums3[i]]) {
      visited[nums3[i]] = true;
      if (exists[nums3[i]]) {
        output[outputSize++] = nums3[i];
      }
    }
  }

  *returnSize = outputSize;
  return output;
}
