void quickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j >= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  quickSort(low, i - 1);
  quickSort(i + 1, high);
}

int minPairSum(int* nums, int numsSize) {
  int* left = nums;
  int* right = nums + numsSize - 1;

  quickSort(left, right);

  int res = 0;
  while (left < right) {
    if (*left + *right > res)
      res = *left + *right;
    ++left;
    --right;
  }

  return res;
}
