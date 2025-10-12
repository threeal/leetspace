int output[2];

int* getNoZeroIntegers(int n, int* returnSize) {
  for (int i = 1; i < n; ++i) {
    int j = i;
    while (j > 0 && j % 10 != 0) j /= 10;
    if (j > 0) continue;

    j = n - i;
    while (j > 0 && j % 10 != 0) j /= 10;
    if (j > 0) continue;

    output[0] = i;
    output[1] = n - i;

    *returnSize = 2;
    return output;
  }

  output[0] = 0;
  output[1] = n;

  *returnSize = 2;
  return output;
}
