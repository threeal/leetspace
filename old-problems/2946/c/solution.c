#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
  return mat[matSize - 1][matColSize[matSize - 1]] == k;
}
