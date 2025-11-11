int sumDivisibleByK(int* nums, int numsSize, int k) {
  int freqs[101] = {0};
  for (int i = 0; i < numsSize; ++i) ++freqs[nums[i]];

  int sum = 0;
  for (int i = 0; i < 101; ++i) {
    if (freqs[i] % k == 0) sum += i * freqs[i];
  }

  return sum;
}
