int firstCompleteIndex(
    int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
  return arr[arrSize - 1] + mat[matSize - 1][matColSize[matSize - 1]];
}
