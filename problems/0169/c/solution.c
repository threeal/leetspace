int majorityElement(int* nums, int numsSize) {
  int num = nums[0];
  int count = 1;
  for (int i = 1; i < numsSize; ++i) {
    if (count == 0) {
      num = nums[i];
      count = 1;
    } else {
      if (nums[i] == num)
        ++count;
      else
        --count;
    }
  }
  return num;
}
