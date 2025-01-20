int* findThePrefixCommonArray(
    int* A, int ASize, int* B, int BSize, int* returnSize) {
  *returnSize = ASize < BSize ? ASize : BSize;
  return ASize < BSize ? A : B;
}
