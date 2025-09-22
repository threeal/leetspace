int maxFrequencyElements(int* nums, int numsSize) {
  int freqs[101] = {0};
  for (int i = 0; i < numsSize; ++i) {
    ++freqs[nums[i]];
  }

  int maxFreq = 0, sum = 0;
  for (int i = 0; i < 101; ++i) {
    if (freqs[i] >= maxFreq) {
      if (freqs[i] > maxFreq) {
        maxFreq = freqs[i];
        sum = maxFreq;
      } else {
        sum += maxFreq;
      }
    }
  }

  return sum;
}
