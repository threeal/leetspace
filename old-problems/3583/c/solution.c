int specialTriplets(int* nums, int numsSize) {
  long long rFreqs[200001] = {0};
  for (int i = 0; i < numsSize; ++i) ++rFreqs[nums[i]];

  long long triplets = 0;
  long long lFreqs[200001] = {0};
  for (int i = 0; i < numsSize; ++i) {
    --rFreqs[nums[i]];
    const int num2 = nums[i] * 2;
    if (lFreqs[num2] != 0 && rFreqs[num2] != 0) {
      triplets = (triplets + (lFreqs[num2] * rFreqs[num2])) % 1000000007;
    }
    ++lFreqs[nums[i]];
  }

  return triplets;
}
