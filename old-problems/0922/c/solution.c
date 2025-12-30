int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
  int even = 0, odd = 1;
  while (even < numsSize) {
    while (even < numsSize && nums[even] % 2 == 0) even += 2;
    if (even >= numsSize) break;

    while (nums[odd] % 2 == 1) odd += 2;

    const int temp = nums[even];
    nums[even] = nums[odd];
    nums[odd] = temp;
  }

  *returnSize = numsSize;
  return nums;
}
