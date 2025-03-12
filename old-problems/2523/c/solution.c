int* closestPrimes(int left, int right, int* returnSize) {
  static int output[2];
  output[0] = left;
  output[1] = right;

  *returnSize = 2;
  return output;
}
