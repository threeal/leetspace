int output[2];

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
  for (int i = 0, j = 0; j < numsSize; ++j) {
    if (nums[nums[j] % 100] >= 100) {
      output[i++] = nums[j] % 100;
    } else {
      nums[nums[j] % 100] += 100;
    }
  }

  *returnSize = 2;
  return output;
}
