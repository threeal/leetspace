int maximumProduct(int* nums, int numsSize) {
  int temp;
  if (nums[0] > nums[1]) {
    temp = nums[0];
    nums[0] = nums[1];
    nums[1] = temp;
  }

  for (int i = 2; i < numsSize; ++i) {
    if (nums[i] < nums[1]) {
      if (nums[i] < nums[0]) {
        temp = nums[1];
        nums[1] = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
      } else {
        temp = nums[1];
        nums[1] = nums[i];
        nums[i] = temp;
      }
    }
  }

  if (nums[numsSize - 2] > nums[numsSize - 1]) {
    temp = nums[numsSize - 2];
    nums[numsSize - 2] = nums[numsSize - 1];
    nums[numsSize - 1] = temp;
  }

  if (nums[numsSize - 3] > nums[numsSize - 2]) {
    if (nums[numsSize - 3] > nums[numsSize - 1]) {
      temp = nums[numsSize - 3];
      nums[numsSize - 3] = nums[numsSize - 2];
      nums[numsSize - 2] = nums[numsSize - 1];
      nums[numsSize - 1] = temp;
    } else {
      temp = nums[numsSize - 3];
      nums[numsSize - 3] = nums[numsSize - 2];
      nums[numsSize - 2] = temp;
    }
  }

  for (int i = numsSize - 4; i >= 2; --i) {
    if (nums[i] > nums[numsSize - 3]) {
      if (nums[i] > nums[numsSize - 1]) {
        nums[numsSize - 3] = nums[numsSize - 2];
        nums[numsSize - 2] = nums[numsSize - 1];
        nums[numsSize - 1] = nums[i];
      } else if (nums[i] > nums[numsSize - 2]) {
        nums[numsSize - 3] = nums[numsSize - 2];
        nums[numsSize - 2] = nums[i];
      } else {
        nums[numsSize - 3] = nums[i];
      }
    }
  }

  const int lowAndHigh = nums[0] * nums[1] * nums[numsSize - 1];
  const int high = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
  return lowAndHigh > high ? lowAndHigh : high;
}
