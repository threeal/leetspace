int findGCD(int* nums, int numsSize) {
  int smallest = nums[0];
  int largest = nums[0];
  for (int i = numsSize - 1; i > 0; --i) {
    if (smallest > nums[i]) smallest = nums[i];
    if (largest < nums[i]) largest = nums[i];
  }

  while (smallest != 0) {
    const int temp = smallest;
    smallest = largest;
    largest = temp;

    smallest %= largest;
  }

  return largest;
}
