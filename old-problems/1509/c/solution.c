#include <limits.h>

int minDifference(int* nums, int numsSize) {
  if (numsSize <= 4) return 0;

  int maxA = INT_MIN;
  int maxB = INT_MIN;
  int maxC = INT_MIN;
  int maxD = INT_MIN;

  int minA = INT_MAX;
  int minB = INT_MAX;
  int minC = INT_MAX;
  int minD = INT_MAX;

  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] > maxA) {
      maxD = maxC;
      maxC = maxB;
      maxB = maxA;
      maxA = nums[i];
    } else if (nums[i] > maxB) {
      maxD = maxC;
      maxC = maxB;
      maxB = nums[i];
    } else if (nums[i] > maxC) {
      maxD = maxC;
      maxC = nums[i];
    } else if (nums[i] > maxD) {
      maxD = nums[i];
    }

    if (nums[i] < minA) {
      minD = minC;
      minC = minB;
      minB = minA;
      minA = nums[i];
    } else if (nums[i] < minB) {
      minD = minC;
      minC = minB;
      minB = nums[i];
    } else if (nums[i] < minC) {
      minD = minC;
      minC = nums[i];
    } else if (nums[i] < minD) {
      minD = nums[i];
    }
  }

  if (maxA - minD < maxB - minC) {
    if (maxA - minD < maxC - minB) {
      if (maxA - minD < maxD - minA) {
        return maxA - minD;
      } else {
        return maxD - minA;
      }
    } else {
      if (maxC - minB < maxD - minA) {
        return maxC - minB;
      } else {
        return maxD - minA;
      }
    }
  } else {
    if (maxB - minC < maxC - minB) {
      if (maxB - minC < maxD - minA) {
        return maxB - minC;
      } else {
        return maxD - minA;
      }
    } else {
      if (maxC - minB < maxD - minA) {
        return maxC - minB;
      } else {
        return maxD - minA;
      }
    }
  }
}
