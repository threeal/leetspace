static int findGcd(int a, int b) {
  int tmp;
  while (b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a < 0 ? -a : a;
}

int minOperations(int* nums, int numsSize) {
  int ones = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 1) ++ones;
  }

  if (ones > 0) return numsSize - ones;

  int minLen = numsSize + 1;
  for (int i = 0; i < numsSize; ++i) {
    int minNum = nums[i];
    int maxJ = numsSize <= i + minLen ? numsSize : i + minLen;
    for (int j = i + 1; j < maxJ; ++j) {
      minNum = findGcd(minNum, nums[j]);
      if (minNum == 1) {
        minLen = j + 1 - i;
        break;
      }
    }
  }

  return minLen <= numsSize ? numsSize + minLen - 2 : -1;
}
