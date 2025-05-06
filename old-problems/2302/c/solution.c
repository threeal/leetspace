long long countSubarrays(int* nums, int numsSize, long long k) {
  long long count = 0, sum = 0, n = numsSize;
  for (long long l = 0, r = 0; r < n; ++r) {
    sum += nums[r];
    while (sum * (r + 1 - l) >= k) sum -= nums[l++];
    count += r + 1 - l;
  }
  return count;
}
