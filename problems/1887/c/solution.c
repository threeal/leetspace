int reductionOperations(int* nums, int numsSize) {
  int maxNum = 1;
  int minNum = 5000;

  int frequencies[50001] = {0};
  for (int i = 0; i < numsSize; ++i) {
    ++frequencies[nums[i]];
    if (nums[i] > maxNum) maxNum = nums[i];
    if (nums[i] < minNum) minNum = nums[i];
  }

  int frequencySum = 0;
  int operations = 0;
  for (int num = maxNum; num > minNum; --num) {
    if (frequencies[num] == 0) continue;
    frequencySum += frequencies[num];
    operations += frequencySum;
  }

  return operations;
}
