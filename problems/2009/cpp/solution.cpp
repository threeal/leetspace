class Solution {
 public:
  int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int res = 0;

    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int unchanged = 1;
      int need_changed = n - 1;

      int j = i + 1;
      while (j < n && need_changed > 0) {
        if (nums[j] != nums[j - 1]) {
          need_changed -= nums[j] - nums[j - 1];
          if (need_changed >= 0) {
            ++unchanged;
          }
        }
        ++j;
      }

      res = max(res, unchanged);
    }

    return n - res;
  }
};
