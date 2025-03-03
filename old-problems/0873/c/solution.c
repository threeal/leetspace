#include <stdlib.h>
#include <string.h>

int lenLongestFibSubseq(int* arr, int arrSize) {
  int longest = 0;

  const int countsSize = arrSize - 1;
  int** counts = malloc(countsSize * sizeof(int*));
  for (int i = 0; i < countsSize; ++i) {
    counts[i] = malloc((i + 1) * sizeof(int));
    memset(counts[i], 0, (i + 1) * sizeof(int));
  }

  for (int j = arrSize - 2; j > 0; --j) {
    for (int i = 0, k = i + 1; i < j; ++i) {
      while (k < arrSize && arr[i] + arr[j] > arr[k]) ++k;
      if (k < arrSize && arr[i] + arr[j] == arr[k]) {
        counts[j - 1][i] = 1 + counts[k - 1][j];
        if (counts[j - 1][i] > longest) longest = counts[j - 1][i];
      }
    }
  }

  for (int i = 0; i < countsSize; ++i) free(counts[i]);
  free(counts);

  return longest > 0 ? 2 + longest : 0;
}
