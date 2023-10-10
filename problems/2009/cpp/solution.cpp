class Solution {
 public:
  int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int count = 0;

    const int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] > 1) ++count;
    }

    return count;
  }
};
