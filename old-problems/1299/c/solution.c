int* replaceElements(int* arr, int arrSize, int* returnSize) {
  int max = arr[arrSize - 1];
  arr[arrSize - 1] = -1;

  for (int i = arrSize - 2; i >= 0; --i) {
    if (arr[i] > max) {
      int temp = arr[i];
      arr[i] = max;
      max = temp;
    } else {
      arr[i] = max;
    }
  }

  *returnSize = arrSize;
  return arr;
}
