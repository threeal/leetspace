class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    const auto unique_nums = vector(nums.begin(), unique(nums.begin(), nums.end()));
    const int unique_n = unique_nums.size();

    int res = numeric_limits<int>::max();
    for (int a = 0; a < unique_n; ++a) {
      const int b_val = unique_nums[a] + n - 1;
      const auto it = upper_bound(unique_nums.begin(), unique_nums.end(), b_val);
      const int b = distance(unique_nums.begin(), it);
      res = min(res, n - (b - a));
    }

    return res;
  }
};
