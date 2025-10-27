int numSubarraysWithSum(int* nums, int numsSize, int goal) {
  int sum = 0, zeros = 0, count = 0;
  for (int l = 0, r = 0; r < numsSize; ++r) {
    sum += nums[r];
    while (l < r) {
      if (nums[l] == 0) {
        ++zeros;
        ++l;
      } else if (sum > goal) {
        zeros = 0;
        ++l;
        --sum;
      } else {
        break;
      }
    }

    if (sum == goal) count += 1 + zeros;
  }
  return count;
}
