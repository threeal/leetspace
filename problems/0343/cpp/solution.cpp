class Solution {
 public:
  int integerBreak(int n) {
    int res = 0;
    for (int i = 2; i <= n; ++i) {
      const int div = n / i;
      const int mod = n % i;

      vector<int> nums(i, div);
      if (mod > 0) {
        for (int j = 0; j < mod; ++j) {
          ++nums[j];
        }
      }

      const int new_res = multiplies(nums);

      if (new_res > res) {
        res = new_res;
      }
    }

    return res;
  }

  int multiplies(const vector<int>& nums) {
    int total = 1;
    for (int num : nums) {
      total *= num;
    }
    return total;
  }
};
