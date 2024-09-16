int findGcd(int a, int b);

int countBeautifulPairs(int* nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    while (nums[i] > 9) nums[i] /= 10;
    for (int j = i + 1; j < numsSize; ++j) {
      if (findGcd(nums[i], nums[j] % 10) == 1) ++count;
    }
  }
  return count;
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
