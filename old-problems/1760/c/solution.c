int minimumSize(int* nums, int numsSize, int maxOperations) {
  int min = 1;

  int max = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > max) max = nums[i];
  }

  while (min < max) {
    int mid = min + (max - min) / 2;

    int operations = 0;
    for (int i = 0; i < numsSize; ++i) {
      operations += (nums[i] - 1) / mid;
    }

    if (operations > maxOperations) {
      min = mid + 1;
    } else {
      max = mid;
    }
  }

  return min;
}
