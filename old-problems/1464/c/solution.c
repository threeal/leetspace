// The solution can simply be accomplished by finding the two largest elements and then multiplying them.

int maxProduct(int* nums, int numsSize) {
  // Prepare containers for storing two largest elements.
  // a should be smaller than b.
  int a = nums[0] < nums[1] ? nums[0] : nums[1];
  int b = nums[0] < nums[1] ? nums[1] : nums[0];

  // Iterating over the elements to find the two largest elements.
  for (int i = 2; i < numsSize; ++i) {
    if (nums[i] < a) continue;

    if (nums[i] < b) {
      a = nums[i];
    } else {
      a = b;
      b = nums[i];
    }
  }

  // Multiply them after decrementing each by 1.
  return --a * --b;
}
