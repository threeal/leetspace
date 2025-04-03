long long maximumTripletValue(int* nums, int numsSize) {
  long long maxTriplet = 0, maxDiff = 0, maxVal = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (maxDiff * nums[i] > maxTriplet) maxTriplet = maxDiff * nums[i];
    if (maxVal - nums[i] > maxDiff) maxDiff = maxVal - nums[i];
    if (nums[i] > maxVal) maxVal = nums[i];
  }
  return maxTriplet;
}
