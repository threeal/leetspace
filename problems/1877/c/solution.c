void quickSort(int* nums, int low, int high) {
  if (low >= high) return;

  int pivot = nums[high];
  int i = (low - 1);

  for (int j = low; j < high; ++j) {
    if (nums[j] >= pivot) continue;
    ++i;
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  ++i;
  int temp = nums[i];
  nums[i] = nums[high];
  nums[high] = temp;

  quickSort(nums, low, i - 1);
  quickSort(nums, i + 1, high);
}

int minPairSum(int* nums, int numsSize) {
  quickSort(nums, 0, numsSize - 1);

  int left = 0;
  int right = numsSize - 1;

  int res = 0;
  while (left < right) {
    if (nums[left] + nums[right] > res)
      res = nums[left] + nums[right];
    ++left;
    --right;
  }

  return res;
}
