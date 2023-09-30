class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    const size_t n = nums.size();
    for (size_t i = 0; i < n - 2; ++i) {
      for (size_t k = i + 2; k < n; ++k) {
        if (nums[i] >= nums[k]) continue;
        for (size_t j = i + 1; j < k; ++j) {
          if (nums[k] < nums[j]) return true;
        }
      }
    }
    return false;
  }
};
