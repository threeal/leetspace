// The solution can be done simply by counting the frequencies and then
// iterating through the frequencies from largest to smallest to count the required number of operations.

int reductionOperations(int* nums, int numsSize) {
  // Count the frequencies and find the minimum and maximum numbers.
  int frequencies[50001] = {0};
  int maxNum = 1;
  int minNum = 5000;
  for (int i = 0; i < numsSize; ++i) {
    ++frequencies[nums[i]];
    if (nums[i] > maxNum) maxNum = nums[i];
    if (nums[i] < minNum) minNum = nums[i];
  }

  // Iterating through the frequencies to count the required number of operations.
  int frequencySum = 0;
  int operations = 0;
  for (int num = maxNum; num > minNum; --num) {
    if (frequencies[num] == 0) continue;
    frequencySum += frequencies[num];
    operations += frequencySum;
  }

  return operations;
}
