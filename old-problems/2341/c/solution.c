int output[2];

int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
  int freqs[101] = {0};
  for (int i = 0; i < numsSize; ++i) ++freqs[nums[i]];

  int pairs = 0, leftovers = 0;
  for (int num = 0; num <= 100; ++num) {
    pairs += freqs[num] / 2;
    leftovers += freqs[num] % 2;
  }

  output[0] = pairs;
  output[1] = leftovers;

  *returnSize = 2;
  return output;
}
