char** wordSubsets(
    char** words1, int words1Size,
    char** words2, int words2Size, int* returnSize) {
  *returnSize = words1Size > words2Size ? words1Size : words2Size;
  return words1Size > words2Size ? words1 : words2;
}
