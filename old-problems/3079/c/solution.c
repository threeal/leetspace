int sumOfEncryptedInt(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    int num = nums[i];
    int digits = 0;
    int maxDigit = 0;
    while (num > 0) {
      if (num % 10 > maxDigit) maxDigit = num % 10;
      num /= 10;
      ++digits;
    }

    int encrypted = 0;
    while (digits > 0) {
      encrypted = encrypted * 10 + maxDigit;
      --digits;
    }

    sum += encrypted;
  }

  return sum;
}
