int minSwaps(int* nums, int numsSize) {
  int ones = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] == 1) ++ones;
  }
  if (ones == 0) return 0;

  int zeros = 0;
  for (int i = numsSize - ones + 1; i < numsSize; ++i) {
    if (nums[i] == 0) ++zeros;
  }

  int minZeros = ones;
  int left = numsSize - ones;
  int right = numsSize - 1;
  while (left >= 0) {
    if (nums[left] == 0) ++zeros;
    if (zeros < minZeros) minZeros = zeros;
    if (nums[right] == 0) --zeros;
    --left;
    --right;
  }

  left += numsSize;
  while (right >= 0) {
    if (nums[left] == 0) ++zeros;
    if (zeros < minZeros) minZeros = zeros;
    if (nums[right] == 0) --zeros;
    --left;
    --right;
  }

  return minZeros;
}
