int maxProductDifference(int* nums, int numsSize) {
  // Sort the first 4 elements.
  for (int i = 1; i < 4; ++i) {
    if (nums[i] < nums[i - 1]) {
      const int temp = nums[i];
      nums[i] = nums[i - 1];
      nums[i - 1] = temp;
      i = 0;
    }
  }

  // Store the 2 largest elements in `a` and `b`.
  // `b` should be larger than `a`.
  int a = nums[2];
  int b = nums[3];

  // Store the 2 smallest elements in `c` and `d`.
  // `d` should be smaller than `c`.
  int c = nums[1];
  int d = nums[0];

  // Iterate over the rest of the elements to update
  // the largest and smallest elements.
  for (int i = 4; i < numsSize; ++i) {
    if (nums[i] > a) {
      if (nums[i] > b) {
        a = b;
        b = nums[i];
      } else {
        a = nums[i];
      }
    } else if (nums[i] < c) {
      if (nums[i] < d) {
        c = d;
        d = nums[i];
      } else {
        c = nums[i];
      }
    }
  }

  // Calculate the maximum product difference.
  return (a * b) - (c * d);
}
