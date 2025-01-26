int output[2];

int* majorityElement(int* nums, int numsSize, int* returnSize) {
  int majority1 = 0, majority2 = 0, count1 = 0, count2 = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == majority1) {
      ++count1;
    } else if (nums[i] == majority2) {
      ++count2;
    } else if (count1 == 0) {
      majority1 = nums[i];
      ++count1;
    } else if (count2 == 0) {
      majority2 = nums[i];
      ++count2;
    } else {
      --count1;
      --count2;
    }
  }

  count1 = 0;
  count2 = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == majority1) {
      ++count1;
    } else if (nums[i] == majority2) {
      ++count2;
    }
  }

  const int limit = numsSize / 3;
  if (count1 > limit) {
    if (count2 > limit) {
      output[0] = majority1;
      output[1] = majority2;
      *returnSize = 2;
    } else {
      output[0] = majority1;
      *returnSize = 1;
    }
  } else {
    if (count2 > limit) {
      output[0] = majority2;
      *returnSize = 1;
    } else {
      *returnSize = 0;
    }
  }

  return output;
}
