class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    if (target < nums[left]) return left;
    if (target > nums[right]) return right + 1;

    while (right - left > 1) {
      int x = left + (right - left) / 2;
      if (nums[x] == target) return x;
      if (nums[x] < target) {
        left = x;
      } else {
        right = x;
      }
    }

    return right;
  }
};
