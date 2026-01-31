int sumFourDivisors(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    int a = 2;
    while (a * a < nums[i] && nums[i] % a != 0) ++a;

    if (a * a < nums[i]) {
      int b = a + 1;
      while (b * b < nums[i] && nums[i] % b != 0) ++b;

      if (b * b > nums[i]) {
        sum += 1 + a + nums[i] / a + nums[i];
      }
    }
  }

  return sum;
}
