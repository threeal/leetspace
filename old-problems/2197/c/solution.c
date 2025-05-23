int findGcd(int a, int b);

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
  int out = -1;
  for (int i = 0; i < numsSize; ++i) {
    while (out >= 0) {
      const int gcd = findGcd(nums[out], nums[i]);
      if (gcd == 1) break;
      nums[i] /= gcd;
      nums[i] *= nums[out];
      --out;
    }
    nums[++out] = nums[i];
  }
  *returnSize = out + 1;
  return nums;
}

int findGcd(int a, int b) {
  int tmp;
  while (b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a < 0 ? -a : a;
}
