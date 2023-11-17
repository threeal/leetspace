class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    size_t left = 0;
    size_t right = nums.size() - 1;

    int res = 0;
    while (left < right) {
      res = max(res, nums[left] + nums[right]);
      ++left;
      --right;
    }

    return res;
  }
};
