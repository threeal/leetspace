int output[2];

int* rowAndMaximumOnes(
    int** mat, int matSize, int* matColSize, int* returnSize) {
  int maxI = 0, maxCount = 0;
  for (int i = 0; i < matSize; ++i) {
    int count = 0;
    for (int j = 0; j < matColSize[i]; ++j) {
      if (mat[i][j] == 1) ++count;
    }

    if (count > maxCount) {
      maxI = i;
      maxCount = count;
    }
  }

  output[0] = maxI;
  output[1] = maxCount;

  *returnSize = 2;
  return output;
}
