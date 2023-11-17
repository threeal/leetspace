// The solution can be done simply by first sorting the array and then
// iterating from left and right to get the minimized sum of pairs.

void quickSort(int* low, int* high);

int minPairSum(int* nums, int numsSize) {
  // Declare left and right pointers.
  int* left = nums;
  int* right = nums + numsSize - 1;

  // Sort the given array.
  quickSort(left, right);

  // Iterate from left and right to get the maximum sum of each pair.
  int res = 0;
  while (left < right) {
    if (*left + *right > res)
      res = *left + *right;
    ++left;
    --right;
  }

  return res;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
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
