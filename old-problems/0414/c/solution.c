int thirdMax(int* nums, int numsSize) {
  int a = nums[0];

  int i = 1;
  while (i < numsSize && nums[i] == a) ++i;
  if (i == numsSize) return a;
  int b = nums[i];
  if (b > a) {
    const int temp = a;
    a = b;
    b = temp;
  };

  ++i;
  while (i < numsSize && (nums[i] == a || nums[i] == b)) ++i;
  if (i == numsSize) return a;
  int c = nums[i];
  if (c > b) {
    const int temp = c;
    c = b;
    b = temp;
  }
  if (b > a) {
    const int temp = b;
    b = a;
    a = temp;
  }

  ++i;
  while (i < numsSize) {
    if (nums[i] >= a) {
      if (nums[i] > a) {
        c = b;
        b = a;
        a = nums[i];
      }
    } else if (nums[i] >= b) {
      if (nums[i] > b) {
        c = b;
        b = nums[i];
      }
    } else if (nums[i] > c) {
      c = nums[i];
    }
    ++i;
  }

  return c;
}
