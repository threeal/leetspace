#include <stdlib.h>
#include <string.h>

static void fill(int*** it, int* arr, int i, int start, int n, int k);

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
  int size = 1;
  for (int i = 1; i <= k; ++i) {
    size *= n - k + i;
    size /= i;
  }

  *returnSize = size;
  *returnColumnSizes = malloc(size * sizeof(int));
  int** output = malloc(size * sizeof(int*));
  for (int i = 0; i < size; ++i) {
    (*returnColumnSizes)[i] = k;
    output[i] = malloc(k * sizeof(int));
  }

  int** it = output;
  int* arr = malloc(k * sizeof(int));
  fill(&it, arr, 0, 1, n, k);

  free(arr);
  return output;
}

static void fill(int*** it, int* arr, int i, int start, int n, int k) {
  const int end = n - (k - i - 1);
  if (i + 1 == k) {
    for (int j = start; j <= end; ++j) {
      arr[i] = j;
      memcpy(**it, arr, k * sizeof(int));
      ++(*it);
    }
  } else {
    for (int j = start; j <= end; ++j) {
      arr[i] = j;
      fill(it, arr, i + 1, j + 1, n, k);
    }
  }
}
