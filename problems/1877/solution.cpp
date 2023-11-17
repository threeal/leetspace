// The solution can be done simply by first sorting the array and then
// iterating from left and right to get the minimized sum of pairs.

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    // Sort the given array.
    sort(nums.begin(), nums.end());

    // Declare left and right pointers.
    size_t left = 0;
    size_t right = nums.size() - 1;

    // Iterate from left and right to get the maximum sum of each pair.
    int res = 0;
    while (left < right) {
      res = max(res, nums[left] + nums[right]);
      ++left;
      --right;
    }

    return res;
  }
};
