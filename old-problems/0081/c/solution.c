#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
  if (nums[0] == target || nums[numsSize - 1] == target) return true;

  int front = 0, back = numsSize - 1;
  while (nums[front] == nums[0] && nums[back] == nums[numsSize - 1] &&
         front < back) {
    ++front;
    --back;
  }

  if (front > back) return false;

  if (target <= nums[back]) {
    if (target == nums[back]) return true;

    int low = front, high = back;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (nums[mid] > nums[back] || nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return nums[low] == target;
  } else if (target >= nums[front]) {
    if (target == nums[front]) return true;

    int low = front, high = back;
    while (low < high) {
      const int mid = high - (high - low) / 2;
      if (nums[mid] < nums[front] || nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }

    return nums[low] == target;
  }

  return false;
}
