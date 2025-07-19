int sumOfUnique(int* nums, int numsSize) {
  int sum = 0, freqs[101] = {0};
  for (int i = 0; i < numsSize; ++i) {
    switch (++freqs[nums[i]]) {
      case 1:
        sum += nums[i];
        break;

      case 2:
        sum -= nums[i];
        break;
    }
  }
  return sum;
}
