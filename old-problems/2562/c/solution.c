long long findTheArrayConcVal(int* nums, int numsSize) {
  long long sum = 0;

  int l = 0, r = numsSize - 1;
  while (l < r) {
    long long exp = 10, num = nums[r];
    while (exp <= num) exp *= 10;
    sum += exp * nums[l] + num;
    ++l, --r;
  }

  if (l == r) sum += nums[l];

  return sum;
}
