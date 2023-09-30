class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    const size_t n = nums.size();
    for (size_t i = 0; i < n - 2; ++i) {
      int highest = nums[i + 1];
      for (size_t k = i + 2; k < n; ++k) {
        if (nums[i] < nums[k] && nums[k] < highest) {
          return true;
        }
        highest = max(highest, nums[k]);
      }
    }
    return false;
  }
};
