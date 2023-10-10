class Solution {
 public:
  int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    bool prev_counted = false;
    int count = 0;

    const int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] == 1) {
        prev_counted = false;
        continue;
      }
      if (nums[i] - nums[i - 1] > 1) {
        prev_counted = true;
        ++count;
        continue;
      }
      if (prev_counted) {
        ++count;
      }
    }

    return count;
  }
};
