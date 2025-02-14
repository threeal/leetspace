#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int tupleSameProduct(int* nums, int numsSize) {
  int productsSize = 0;
  int* products = malloc(numsSize * (numsSize - 1) / 2 * sizeof(int));

  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      products[productsSize++] = nums[i] * nums[j];
    }
  }

  qsort(products, productsSize, sizeof(int), compare);

  int count = 0;
  for (int i = 1; i < productsSize; ++i) {
    int n = 1;
    while (i < productsSize && products[i] == products[i - 1]) {
      ++i;
      ++n;
    }
    count += n * (n - 1) * 4;
  }

  return count;
}
