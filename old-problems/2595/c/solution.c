int output[2];

int* evenOddBit(int n, int* returnSize) {
  output[0] = 0;
  output[1] = 0;
  for (int i = 1; i <= n; i <<= 1) {
    if ((n & i) != 0) ++output[0];
    if ((i <<= 1) > n) break;
    if ((n & i) != 0) ++output[1];
  }
  *returnSize = 2;
  return output;
}
