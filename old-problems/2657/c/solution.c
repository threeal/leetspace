int* findThePrefixCommonArray(
    int* A, int ASize, int* B, int BSize, int* returnSize) {
  (void)BSize;
  unsigned long long a = 0, b = 0;
  for (int i = 0; i < ASize; ++i) {
    a |= 1l << A[i];
    b |= 1l << B[i];
    A[i] = __builtin_popcountll(a & b);
  }
  *returnSize = ASize;
  return A;
}
